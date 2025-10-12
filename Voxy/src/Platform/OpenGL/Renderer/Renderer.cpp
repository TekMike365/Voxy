#include "Renderer.hpp"

#include <glad/glad.h>

namespace Voxy::Renderer {

void OpenGL_Renderer::Render() {
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL_Renderer::SubmitMesh(uint32_t meshId, uint32_t shaderId,
                                 IMesh::Object meshObject, size_t count) {
    glBindVertexArray(meshId);
    glUseProgram(shaderId);

    if (count == 1)
        glDrawElements(GL_TRIANGLES, meshObject.indexCount, GL_UNSIGNED_INT,
                       (void *)(meshObject.pointer * sizeof(uint32_t)));
    else
        glDrawElementsInstanced(
            GL_TRIANGLES, meshObject.indexCount, GL_UNSIGNED_INT,
            (void *)(meshObject.pointer * sizeof(uint32_t)), count);

    glUseProgram(0);
    glBindVertexArray(0);
}

} // namespace Voxy::Renderer
