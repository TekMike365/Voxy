#include "Renderer.hpp"

#include <glad/glad.h>

namespace Voxy::Renderer {

void OpenGL_Renderer::Render() {
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    RenderMeshes();
}

void OpenGL_Renderer::SubmitMesh(const Ref<Mesh> &mesh,
                                 const Ref<Shader> &shader,
                                 const std::string &objectName, size_t count) {
    MeshRenderCommandStruct mrcs = {mesh, shader, objectName, count};
    m_Commands.emplace_back(mrcs);
}

void OpenGL_Renderer::RenderMeshes() {
    for (auto e : m_Commands) {
        e.mesh->Bind();
        e.shader->Bind();

        auto &object = e.mesh->GetObject(e.objectName);

        if (e.count == 1)
            glDrawElements(GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
                           (void *)(object.pointer * sizeof(uint32_t)));
        else
            glDrawElementsInstanced(
                GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
                (void *)(object.pointer * sizeof(uint32_t)), e.count);

        e.mesh->Unbind();
        e.shader->Unbind();
    }

    m_Commands.clear();
}

} // namespace Voxy::Renderer
