#include "OpenGL_GraphicsContext.hpp"

#include "Log.hpp"

namespace Voxy {

Ref<GraphicsContext> GraphicsContext::Create() {
    return std::make_shared<OpenGL_GraphicsContext>();
}

OpenGL_GraphicsContext::OpenGL_GraphicsContext() {
    m_Renderer = std::make_shared<OpenGL_Renderer>();
    VoxyCoreTrace("Creating Graphics context. Using OpenGL");
}

} // namespace Voxy
