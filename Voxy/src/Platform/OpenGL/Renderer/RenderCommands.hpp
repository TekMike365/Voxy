#pragma once

#include "ECS/Transform.hpp"
#include "Renderer/Shader.hpp"
#include "VertexArray.hpp"

namespace Voxy::Renderer {

struct OpenGL_DrawVertexArrayCommand {
    Transform transform;
    VertexArray::Object object;
    Ref<VertexArray> mesh;
    Ref<Shader> shader;
    size_t count;

    void Execute() const;
};

} // namespace Voxy::Renderer
