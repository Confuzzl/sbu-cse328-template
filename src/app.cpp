#include "app.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <fmt/color.h>
#include <fmt/format.h>
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <imgui.h>

#include <stdexcept>

#include "callback.h"
#include "util.h"

Initializer::Initializer() {
  if (!glfwInit()) {
    throw std::runtime_error{"GLFW FAILED TO INIT"};
  }

  glfwWindowHint(GLFW_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
  window = glfwCreateWindow(DEFAULT_DIMENSIONS.x, DEFAULT_DIMENSIONS.y,
                            "Template", nullptr, nullptr);
  glfwGetFramebufferSize(window, &framebufferSize.x, &framebufferSize.y);
  glfwGetWindowSize(window, &windowSize.x, &windowSize.y);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  if (!gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress))) {
    throw std::runtime_error{"GLAD FAILED TO LOAD"};
  }
}

App::App() : Initializer{} {
  glfwSetErrorCallback(callback::error);
  glfwSetFramebufferSizeCallback(window, callback::framebufferSize);
  glfwSetWindowSizeCallback(window, callback::windowSize);

  glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode,
                                int action, int mods) {
    app().input.keyCallback(window, key, scancode, action, mods);
  });
  glfwSetCursorPosCallback(window,
                           [](GLFWwindow *window, double xpos, double ypos) {
                             app().input.cursorPosCallback(window, xpos, ypos);
                           });
  glfwSetMouseButtonCallback(
      window, [](GLFWwindow *window, int button, int action, int mods) {
        app().input.mouseButtonCallback(window, button, action, mods);
      });
  glfwSetScrollCallback(window,
                        [](GLFWwindow *window, double xpos, double ypos) {
                          app().input.scrollCallback(window, xpos, ypos);
                        });

  glEnable(GL_DEBUG_OUTPUT);
  glDebugMessageCallback(callback::debug, 0);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable;
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 460");

  ImGui::StyleColorsDark();
  // ImGui::DockSpaceOverViewport();
}
App::~App() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();
}

void App::run() {
  glfwMaximizeWindow(window);

  bool show_demo_window = true;
  bool show_another_window = false;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  ImGuiIO &io = ImGui::GetIO();

  double prevT = glfwGetTime(), currT = prevT;
  while (!glfwWindowShouldClose(window)) {
    currT = glfwGetTime();
    const double dt = currT - prevT;

    glfwPollEvents();
    input.processKeys(dt);

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // ImGui::ShowDemoWindow();
    const auto foo = fmt::format("dt = {}", dt);
    ImGui::Text(foo.c_str());

    // Rendering
    ImGui::Render();
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    renderer.render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);

    prevT = currT;
  }
}
void App::close() { glfwSetWindowShouldClose(window, true); }

App &app() {
  static App instance{};
  return instance;
}