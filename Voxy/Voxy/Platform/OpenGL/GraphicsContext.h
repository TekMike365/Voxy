#pragma once

#include "Voxy/Graphics/GraphicsContext.h"

namespace Voxy::OpenGL
{
    class GraphicsContext : public Voxy::GraphicsContext
    {
    public:
        GraphicsContext(const void *window);
        ~GraphicsContext() = default;

        virtual void MakeCurrent() const override;
        virtual void SwapBuffers() const override;
        virtual void SetViewport(int32_t x, int32_t y, size_t width, size_t height) const override;

    private:
        const void *m_Window;
    };
}
