#pragma once

#include "VertexArray.h"
#include "Shader.h"

namespace Voxy::Renderer
{
    void Submit(const Ref<VertexArray> &va, const Ref<Shader> &shader, const std::string &objectName, size_t count = 1);
}
