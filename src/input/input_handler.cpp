#include "input/input_handler.h"

#include <algorithm>

#include "app.h"

InputHandler::InputHandler()
    : keys{
          {GLFW_KEY_ESCAPE, Key{[](const double) { app().close(); }}},
      } {}

void InputHandler::processKeys(const double dt) {
  for (auto &[keycode, key] : keys)
    key(dt);
}
void InputHandler::keyCallback(GLFWwindow *window, int key, int scancode,
                               int action, int mods) {
  if (const auto iterator = keys.find(key); iterator != keys.cend())
    iterator->second.react(action);
}
void InputHandler::cursorPosCallback(GLFWwindow *window, double xpos,
                                     double ypos) {
  cursorPos = {std::clamp<double>(xpos, 0, app().windowSize.x),
               std::clamp<double>(ypos, 0, app().windowSize.y)};
}
void InputHandler::mouseButtonCallback(GLFWwindow *window, int button,
                                       int action, int mods) {}
void InputHandler::scrollCallback(GLFWwindow *window, double xpos,
                                  double ypos) {}