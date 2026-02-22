#pragma once

#include "gl/glsl_object.h"

struct Renderer {
  struct {
    shaders::Basic basic;
  } shaders;

  void render();
};