#pragma once

#include "Core/GraphicsContext.hpp"
#include "Renderer.hpp"

namespace Voxy::Platform::OpenGL {

class GraphicsContext : public Voxy::GraphicsContext {
public:
    GraphicsContext();

    virtual void SetViewport(int x, int y, int width, int height) override;

    inline virtual Ref<Voxy::Renderer> GetRenderer() const override {
        return m_Renderer;
    }

private:
    Ref<OpenGL::Renderer> m_Renderer;
};

} // namespace Voxy::Platform::OpenGL