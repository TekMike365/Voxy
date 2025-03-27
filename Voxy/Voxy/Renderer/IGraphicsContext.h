#pragma once

#include "Log.h"
#include "Helpers.h"

namespace Voxy
{
    class IWindow;

    enum class GraphicsAPI
    {
        None = 0,
        OpenGL
    };

    class IGraphicsContext
    {
    public:
        virtual void MakeCurrent() const = 0;
        virtual void SwapBuffers() const = 0;
        virtual void SetViewport(int32_t x, int32_t y, size_t width, size_t height) const = 0;

        static Ref<IGraphicsContext> CreateContext(GraphicsAPI api, const Ref<IWindow> &window);
    };
}
