#include "GraphicsContext.h"

#include "Voxy/Platform/OpenGL/GraphicsContext.h"

namespace Voxy
{
    Ref<GraphicsContext> GraphicsContext::Create(const void *window)
    {
        return Ref<GraphicsContext>(new OpenGL::GraphicsContext(window));
    }
}