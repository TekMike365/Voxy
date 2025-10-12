#pragma once

#include "Helpers.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

namespace Voxy::Renderer {

class Renderer {
public:
    virtual void Render() = 0;
    virtual void SubmitMesh(uint32_t meshId, uint32_t shaderId,
                            Mesh::Object meshObject, size_t count = 1) = 0;
};

} // namespace Voxy::Renderer
