#pragma once

#include "Helpers.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"

#include "ECS/Transform.hpp"

namespace Voxy::Renderer {

class Renderer {
public:
    virtual ~Renderer() = default;

    virtual void Render() = 0;
    virtual void SubmitVertexArray(const Ref<VertexArray> &mesh,
                                   const Ref<Shader> &shader,
                                   const std::string &objectName,
                                   const Transform &transform,
                                   size_t count = 1) = 0;
};

} // namespace Voxy::Renderer
