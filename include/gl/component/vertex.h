#pragma once

#include "gl/uniform.h"
#include <glad/gl.h>

#include "gl/component/uniform_macros.h"
#include "gl/vertex_layout.h"

#define VERT_BEGIN(tname, layout, sname)                                       \
  struct tname : Base<layout> {                                                \
    static constexpr char name[] = sname
#define VERT_END                                                               \
  using Base::Base;                                                            \
  }

namespace shaders {
namespace vert {
template <typename VertexLayout> struct Base : UniformHolder {
  using LayoutType = VertexLayout;

  using UniformHolder::UniformHolder;
};

VERT_BEGIN(Basic, vertex_layout::pos, "basic.vert");
NEW_UNIFORM_BLOCK(ViewBlock);
VERT_END;
} // namespace vert
} // namespace shaders

#undef VERT_BEGIN
#undef VERT_END