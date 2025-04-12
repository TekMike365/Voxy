#pragma once

#include "VertexArray.h"
#include "Shader.h"

#include "Voxy/Scene/Components/Camera.h"
#include "Voxy/Scene/Components/Transform.h"

namespace Voxy::Renderer
{
    void Begin(const Camera *camera, const Transform *view);
    void End();

    void Submit(const Ref<VertexArray> &va, const Ref<Shader> &shader, const std::string &objectName, size_t count = 1);
}
