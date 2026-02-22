#pragma once

#include <glad/gl.h>

#include "util.h"

namespace GL {
struct BufferObject {
  GLuint ID;
  GLsizeiptr size;
  GLsizei count = 0;

  BufferObject(const GLsizeiptr size, const GLbitfield flags,
               const void *data = nullptr);
  ~BufferObject();

  void reset() { count = 0; }
};

struct VBO : BufferObject {
  GLsizei stride;

private:
  VBO(const std::size_t count, const GLsizei stride)
      : BufferObject{static_cast<GLsizeiptr>(count * stride),
                     GL_DYNAMIC_STORAGE_BIT},
        stride{stride} {}

public:
  template <typename T> void write(const T &list) {
    count = list.size();
    glNamedBufferSubData(ID, 0, list.size() * sizeof(T::value_type),
                         std::data(list));
  }

  template <typename T> static VBO create(const std::size_t count) {
    return VBO{count, sizeof(T)};
  }
};
struct EBO : BufferObject {
  GLenum type;

  template <typename T>
  EBO(const T &list)
      : BufferObject{list.size() * sizeof(T::value_type),
                     GL_DYNAMIC_STORAGE_BIT, list.data()},
        type{macroOf<typename T::value_type>()} {}
};
} // namespace GL