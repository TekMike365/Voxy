#pragma once

#include "GraphicsContext.hpp"
#include "OpenGL_Renderer.hpp"

namespace Voxy {

class OpenGL_GraphicsContext : public GraphicsContext {
public:
    OpenGL_GraphicsContext();

    virtual void SetViewport(int x, int y, int width, int height) override;

    inline virtual Ref<Renderer> GetRenderer() const override {
        return m_Renderer;
    }

private:
    Ref<OpenGL_Renderer> m_Renderer;
};

} // namespace Voxy