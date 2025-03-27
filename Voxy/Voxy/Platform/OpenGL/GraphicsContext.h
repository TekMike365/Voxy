#pragma once

#include "Voxy/Renderer/IGraphicsContext.h"

namespace Voxy::OpenGL
{
    class GraphicsContext : public IGraphicsContext
    {
    public:
        GraphicsContext(const Ref<IWindow> &window);
        ~GraphicsContext() = default;

        virtual void MakeCurrent() const override;
        virtual void SwapBuffers() const override;
        virtual void SetViewport(int32_t x, int32_t y, size_t width, size_t height) const override;

    private:
        Ref<IWindow> m_Window;
    };
}
