#pragma once

#include "gl/uniform.h"
#include <glad/gl.h>

#include "color.h"
#include "gl/component/uniform_macros.h"
#include "gl/vertex_layout.h"

#define FRAG_COLOR NEW_UNIFORM(Color, frag_color)
#define SAMPLER GL::Sampler sampler{programID, "sampler"}

#define FRAG_BEGIN(tname, sname)                                               \
  struct tname : UniformHolder {                                               \
    static constexpr char name[] = sname
#define FRAG_END                                                               \
  using UniformHolder::UniformHolder;                                          \
  }

namespace shaders {
namespace frag {
FRAG_BEGIN(Basic, "basic.frag");
FRAG_COLOR;
FRAG_END;
} // namespace frag
} // namespace shaders

#undef FRAG_COLOR
#undef SAMPLER
#undef FRAG_BEGIN
#undef FRAG_END