#pragma once

#include "Renderer/Renderer.hpp"

namespace Voxy::Renderer {

// TODO: NO! >:(
struct MeshRenderCommandStruct {
    Ref<Mesh> mesh;
    Ref<Shader> shader;
    std::string objectName;
    size_t count;
};

class OpenGL_Renderer : public Renderer {
public:
    virtual void Render() override;
    virtual void SubmitMesh(const Ref<Mesh> &mesh, const Ref<Shader> &shader,
                            const std::string &objectName,
                            size_t count = 1) override;

private:
    void RenderMeshes();

private:
    std::vector<MeshRenderCommandStruct> m_Commands;
};

} // namespace Voxy::Renderer
