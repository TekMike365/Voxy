#include "IGraphicsContext.h"

#include "Voxy/Platform/OpenGL/GraphicsContext.h"

namespace Voxy
{
    Ref<IGraphicsContext> IGraphicsContext::CreateContext(GraphicsAPI api, const Ref<IWindow> &window)
    {
        switch (api)
        {
            case GraphicsAPI::OpenGL:
                return Ref<IGraphicsContext>(new OpenGL::GraphicsContext(window));
        }

        VOXY_CORE_ERROR("Unknown Graphics API");
    }
}