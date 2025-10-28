#pragma once

#include "Camera.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Transform.hpp"

namespace Voxy::Renderer {

struct IMaterial {};

class Renderer {
public:
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Render() = 0;

    virtual void BeginScene(const Camera &camera) = 0;
    virtual void EndScene() = 0;

    virtual void Submit(const Mesh &mesh, const IMaterial &mat,
                        const Transform &transform, Shader shader) = 0;
};

} // namespace Voxy::Renderer
