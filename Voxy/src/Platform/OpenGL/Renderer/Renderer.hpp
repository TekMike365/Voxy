#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy::Renderer {

class OpenGL_Renderer : public IRenderer {
public:
    virtual void Render() override;
    virtual void SubmitMesh(uint32_t meshId, uint32_t shaderId,
                            IMesh::Object meshObject,
                            size_t count = 1) override;
};

} // namespace Voxy::Renderer
