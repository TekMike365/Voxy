#include "GraphicsContext.h"

#include "Voxy/Platform/OpenGL/GraphicsContext.h"

namespace Voxy
{
    Ref<GraphicsContext> GraphicsContext::CreateContext(GraphicsAPI api, const void *window)
    {
        switch (api)
        {
            case GraphicsAPI::OpenGL:
                return Ref<GraphicsContext>(new OpenGL::GraphicsContext(window));
        }

        VOXY_CORE_ERROR("Unknown Graphics API");
        return nullptr;
    }
}