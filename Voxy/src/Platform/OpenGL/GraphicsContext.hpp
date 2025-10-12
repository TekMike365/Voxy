#pragma once

#include "Core/GraphicsContext.hpp"
#include "Platform/OpenGL/Renderer/Renderer.hpp"

namespace Voxy::Platform {

class OpenGL_GraphicsContext : public IGraphicsContext {
public:
    OpenGL_GraphicsContext();

    virtual void SetViewport(int x, int y, int width, int height) override;

    inline virtual Ref<Renderer::IRenderer> GetRenderer() const override {
        return m_Renderer;
    }

private:
    Ref<Renderer::OpenGL_Renderer> m_Renderer;
};

} // namespace Voxy::Platform