#pragma once

#include "Helpers.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

namespace Voxy::Renderer {

class Renderer {
public:
    virtual void Render() = 0;
    virtual void SubmitMesh(const Ref<Mesh> &mesh, const Ref<Shader> &shader,
                            const std::string &objectName,
                            size_t count = 1) = 0;
};

} // namespace Voxy::Renderer
