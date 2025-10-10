#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy::Renderer {

class OpenGL_Renderer : public Renderer {
public:
    virtual void Render() override;
};

} // namespace Voxy::Renderer
