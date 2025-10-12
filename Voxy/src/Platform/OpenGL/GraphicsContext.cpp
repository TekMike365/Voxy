#include "GraphicsContext.hpp"

#include <glad/glad.h>

#include "Log.hpp"
#include "OpenGL.hpp"

namespace Voxy {

Ref<IGraphicsContext> IGraphicsContext::Create() {
    return std::make_shared<Platform::OpenGL_GraphicsContext>();
}

namespace Platform {

OpenGL_GraphicsContext::OpenGL_GraphicsContext() {
    VoxyCoreTrace("Creating Graphics context. Using OpenGL");

    OpenGL_Init();
    m_Renderer = std::make_shared<Renderer::OpenGL_Renderer>();
}

void OpenGL_GraphicsContext::SetViewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

} // namespace Platform
} // namespace Voxy
