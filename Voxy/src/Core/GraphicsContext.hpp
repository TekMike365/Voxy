#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy {

class IGraphicsContext {
public:
    virtual void SetViewport(int x, int y, int width, int height) = 0;

    virtual Ref<Renderer::IRenderer> GetRenderer() const = 0;

public:
    static Ref<IGraphicsContext> Create();
};

} // namespace Voxy
