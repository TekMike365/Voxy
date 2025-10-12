#pragma once

#include "Helpers.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

namespace Voxy::Renderer {

class IRenderer {
public:
    virtual void Render() = 0;
    virtual void SubmitMesh(uint32_t meshId, uint32_t shaderId,
                            IMesh::Object meshObject, size_t count = 1) = 0;
};

} // namespace Voxy::Renderer
