#pragma once

#include "ECS/Transform.hpp"
#include "Mesh.hpp"
#include "Renderer/Shader.hpp"

namespace Voxy::Renderer {

struct OpenGL_DrawMeshCommand {
    Transform transform;
    Mesh::Object object;
    Ref<Mesh> mesh;
    Ref<Shader> shader;
    size_t count;

    void Execute() const;
};

} // namespace Voxy::Renderer
