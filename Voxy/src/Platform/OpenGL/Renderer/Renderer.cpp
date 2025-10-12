#include "Renderer.hpp"

#include <glad/glad.h>

#include "Mesh.hpp"
#include "Shader.hpp"

namespace Voxy::Renderer {

enum class RenderCommand { None = 0, DrawMesh };

struct DrawMeshData {
    Mesh::Object object;
    size_t count;
    uint32_t meshID;
    uint32_t shaderID;

    DrawMeshData(const Mesh::Object &object, size_t count, uint32_t meshID,
                 uint32_t shaderID)
        : object(object), count(count), meshID(meshID), shaderID(shaderID) {}
};

std::vector<RenderCommand> g_CommandQueue;
std::vector<DrawMeshData> g_DrawMeshQueue;

void DrawMesh() {
    static auto dmesh = g_DrawMeshQueue.begin();
    if (dmesh == g_DrawMeshQueue.end())
        return;

    OpenGL_Mesh::SBind(dmesh->meshID);
    OpenGL_Shader::SBind(dmesh->shaderID);

    if (dmesh->count == 1)
        glDrawElements(GL_TRIANGLES, dmesh->object.indexCount, GL_UNSIGNED_INT,
                       (void *)(dmesh->object.pointer * sizeof(uint32_t)));
    else
        glDrawElementsInstanced(
            GL_TRIANGLES, dmesh->object.indexCount, GL_UNSIGNED_INT,
            (void *)(dmesh->object.pointer * sizeof(uint32_t)), dmesh->count);

    OpenGL_Mesh::SUnbind();
    OpenGL_Shader::SUnbind();

    // TODO: This can be optimised
    g_DrawMeshQueue.erase(dmesh);
}

void FlushCommandQueue() {
    for (auto command : g_CommandQueue) {
        switch (command) {
        case RenderCommand::DrawMesh:
            DrawMesh();
            break;
        default:
            break;
        }
    }

    g_CommandQueue.clear();
}

/*
    Renderer Implementation
*/

void OpenGL_Renderer::Render() {
    glClearColor(0.95f, 0.64f, 0.48f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    FlushCommandQueue();
}

void OpenGL_Renderer::SubmitMesh(const Ref<Mesh> &mesh,
                                 const Ref<Shader> &shader,
                                 const std::string &objectName, size_t count) {
    g_CommandQueue.emplace_back(RenderCommand::DrawMesh);
    g_DrawMeshQueue.emplace_back(mesh->GetObject(objectName), count,
                                 mesh->GetID(), shader->GetID());
}

} // namespace Voxy::Renderer
