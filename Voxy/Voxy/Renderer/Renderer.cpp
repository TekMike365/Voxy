#include "Renderer.h"

#include "RenderCommand.h"

namespace Voxy::Renderer
{
    static Ref<RenderCommand> s_RenderCommand = RenderCommand::Create();

    void Submit(const Ref<VertexArray> &va, const Ref<Shader> &shader, const std::string &objectName)
    {
        va->Bind();
        shader->Bind();
        auto &obj = va->GetObject(objectName);
        s_RenderCommand->DrawIndexed(obj.IndexCount, obj.Pointer);
        va->Unbind();
        shader->Unbind();
    }
}