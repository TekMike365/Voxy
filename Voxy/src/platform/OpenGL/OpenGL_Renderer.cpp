#include "OpenGL_Renderer.hpp"

#include <glad/glad.h>

namespace Voxy {

void OpenGL_Renderer::Render() {
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace Voxy
