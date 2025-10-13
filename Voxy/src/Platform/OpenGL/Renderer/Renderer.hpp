#pragma once

#include "CommandQueue.hpp"
#include "Renderer/Renderer.hpp"

namespace Voxy::Renderer {

class OpenGL_Renderer : public Renderer {
public:
    virtual void Render() override;
    virtual void SubmitMesh(const Ref<Mesh> &mesh, const Ref<Shader> &shader,
                            const std::string &objectName,
                            const Transform &transform, size_t count) override;

private:
    OpenGL_CommandQueue m_CommandQ;
};

} // namespace Voxy::Renderer
