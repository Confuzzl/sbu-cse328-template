#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct App {
  GLFWwindow *window = nullptr;

  App();
  ~App();

  void run();
};

App &app();