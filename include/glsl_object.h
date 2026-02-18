#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "util.h"
#include <initializer_list>

namespace GL {
struct Shader {
  GLuint ID;
  GLenum type;
  const char *name;

  Shader(const GLenum type, const char *const name);
  ~Shader();
  MOVE_ONLY_TYPE(Shader)
};

struct Program {
  GLuint ID;

  Program(const std::initializer_list<Shader> shaders);
  ~Program();
  MOVE_ONLY_TYPE(Program)
};
} // namespace GL

namespace shaders {

}