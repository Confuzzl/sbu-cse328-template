#include "gl/vertex_layout.h"

namespace shaders::vertex_layout {
template <> void enable<pos>(const GLuint vaoID) { enable<glm::vec2>(vaoID); }
template <> void enable<postex>(const GLuint vaoID) {
  enable<glm::vec2, glm::u16vec2>(vaoID);
}
} // namespace shaders::vertex_layout