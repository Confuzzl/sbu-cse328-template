#pragma once

#include <GLFW/glfw3.h>

struct Window {
  GLFWwindow *ptr;

  int width, height;
  const char *name;

  Window(const int w, const int h, const char *const name);

  operator GLFWwindow *();
};