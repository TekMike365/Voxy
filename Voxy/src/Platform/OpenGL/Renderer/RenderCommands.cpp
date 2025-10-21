#include "RenderCommands.hpp"

#include <glad/glad.h>

#include "Shader.hpp"

namespace Voxy::Renderer {

void OpenGL_DrawVertexArrayCommand::Execute() const {
    mesh->Bind();
    shader->Bind();

    shader->UploadUniform(transform.ToMat4(), "uVP");

    if (count == 1)
        glDrawElements(GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
                       (void *)(object.pointer * sizeof(uint32_t)));
    else
        glDrawElementsInstanced(
            GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
            (void *)(object.pointer * sizeof(uint32_t)), count);

    mesh->Unbind();
    shader->Unbind();
}

} // namespace Voxy::Renderer
