#pragma once

#include "Renderer.hpp"

namespace Voxy {

class GraphicsContext {
public:
    virtual Ref<Renderer> GetRenderer() const = 0;

public:
    static Ref<GraphicsContext> Create();
};

} // namespace Voxy
