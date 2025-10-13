#pragma once

#include "Mesh.hpp"
#include "Renderer/Shader.hpp"
#include "Transform.hpp"

namespace Voxy::Renderer {

struct OpenGL_DrawMeshCommand {
    Transform transform;
    Mesh::Object object;
    Ref<Shader> shader; // TODO: No pointers >:(
    size_t count;
    uint32_t meshID;

    void Execute() const;
};

} // namespace Voxy::Renderer
