#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy::Renderer {

class OpenGL_Renderer : public Renderer {
public:
    virtual void Render() override;
    virtual void SubmitMesh(const Ref<Mesh> &mesh, const Ref<Shader> &shader,
                            const std::string &objectName,
                            size_t count = 1) override;
};

} // namespace Voxy::Renderer
