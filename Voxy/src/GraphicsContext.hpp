#pragma once

#include "Renderer.hpp"

namespace Voxy {

class GraphicsContext {
public:
    virtual void SetViewport(int x, int y, int width, int height) = 0;

    virtual Ref<Renderer> GetRenderer() const = 0;

public:
    static Ref<GraphicsContext> Create();
};

} // namespace Voxy
