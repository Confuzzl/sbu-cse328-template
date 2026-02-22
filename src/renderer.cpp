#include "renderer.h"

#include <glm/glm.hpp>

#include "app.h"
#include "color.h"
#include "gl/gl_object.h"
#include "gl/glsl_object.h"
#include "gl/uniform.h"
#include "gl/vertex_layout.h"

static GL::VBO &foo() {
  static auto vbo = GL::VBO::create<shaders::vertex_layout::pos>(3);
  const auto list = {
      glm::vec2{+000, +000},
      glm::vec2{+800, +000},
      glm::vec2{+400, +900},
  };
  vbo.write(list);
  return vbo;
}

void Renderer::render() {
  static auto &vbo = foo();

  {
    using namespace shaders::uniforms;
    shaders::getUBO<ViewBlock>().update(ViewBlock{glm::ortho<float>(
        0, app().framebufferSize.x, 0, app().framebufferSize.y, -1, +1)});
  }

  shaders.basic.setFragColor(RED).draw(GL_TRIANGLES, vbo);
}