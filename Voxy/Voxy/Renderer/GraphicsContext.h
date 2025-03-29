#pragma once

#include "Log.h"
#include "Helpers.h"

namespace Voxy
{
    class Window;

    enum class GraphicsAPI
    {
        None = 0,
        OpenGL
    };

    class GraphicsContext
    {
    public:
        virtual void MakeCurrent() const = 0;
        virtual void SwapBuffers() const = 0;
        virtual void SetViewport(int32_t x, int32_t y, size_t width, size_t height) const = 0;

        static Ref<GraphicsContext> CreateContext(GraphicsAPI api, const void *window);
    };
}
