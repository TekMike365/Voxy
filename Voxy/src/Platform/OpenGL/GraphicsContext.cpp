#include "GraphicsContext.hpp"

#include <glad/glad.h>

#include "Log.hpp"
#include "OpenGL.hpp"

namespace Voxy {

Ref<GraphicsContext> GraphicsContext::Create() {
    return std::make_shared<Platform::OpenGL::GraphicsContext>();
}

namespace Platform::OpenGL {

GraphicsContext::GraphicsContext() {
    VoxyCoreTrace("Creating Graphics context. Using OpenGL");

    OpenGL::Init();
    m_Renderer = std::make_shared<OpenGL::Renderer>();
}

void GraphicsContext::SetViewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

} // namespace Platform::OpenGL
} // namespace Voxy
