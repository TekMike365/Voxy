#include "RenderCommands.hpp"

#include <glad/glad.h>

#include "Shader.hpp"

namespace Voxy::Renderer {

void OpenGL_DrawMeshCommand::Execute() const {
    OpenGL_Mesh::SBind(meshID);
    OpenGL_Shader::SBind(shaderID);

    if (count == 1)
        glDrawElements(GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
                       (void *)(object.pointer * sizeof(uint32_t)));
    else
        glDrawElementsInstanced(
            GL_TRIANGLES, object.indexCount, GL_UNSIGNED_INT,
            (void *)(object.pointer * sizeof(uint32_t)), count);

    OpenGL_Mesh::SUnbind();
    OpenGL_Shader::SUnbind();
}

} // namespace Voxy::Renderer
