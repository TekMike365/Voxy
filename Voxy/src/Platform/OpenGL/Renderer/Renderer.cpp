#include "Renderer.hpp"

#include <glad/glad.h>

#include "Shader.hpp"
#include "VertexArray.hpp"

namespace Voxy::Renderer {

void OpenGL_Renderer::Render() {
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_CommandQ.Flush();
}

void OpenGL_Renderer::SubmitVertexArray(const Ref<VertexArray> &mesh,
                                        const Ref<Shader> &shader,
                                        const std::string &objectName,
                                        const Transform &transform,
                                        size_t count) {
    m_CommandQ.PushDrawVertexArrayCommand(
        {transform, mesh->GetObject(objectName), mesh, shader, count});
}

} // namespace Voxy::Renderer
