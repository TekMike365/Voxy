#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy::Platform::OpenGL {

class Renderer : public Voxy::Renderer {
public:
    virtual void Render() override;
};

} // namespace Voxy::Platform::OpenGL
