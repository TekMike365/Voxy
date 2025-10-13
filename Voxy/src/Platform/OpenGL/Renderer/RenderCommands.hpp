#pragma once

#include "Mesh.hpp"

namespace Voxy::Renderer {

struct OpenGL_DrawMeshCommand {
    Mesh::Object object;
    size_t count;
    uint32_t meshID;
    uint32_t shaderID;

    void Execute() const;
};

} // namespace Voxy::Renderer
