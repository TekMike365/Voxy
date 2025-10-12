#include "Renderer.hpp"

#include <glad/glad.h>

namespace Voxy::Renderer {

void OpenGL_Renderer::Render() {
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL_Renderer::SubmitMesh(Ref<Mesh> mesh, Ref<Shader> shader,
                                 const std::string &objectName, size_t count) {
    mesh->Bind();
    shader->Bind();

    auto &object = mesh->GetObject(objectName);

    if (count == 1)
        glDrawElements(GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
                       (void *)(object.pointer * sizeof(uint32_t)));
    else
        glDrawElementsInstanced(
            GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
            (void *)(object.pointer * sizeof(uint32_t)), count);

    shader->Unbind();
    mesh->Unbind();
}

} // namespace Voxy::Renderer
