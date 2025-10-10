#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy {

class OpenGL_Renderer : public Renderer {
public:
    virtual void Render() override;
};

} // namespace Voxy
