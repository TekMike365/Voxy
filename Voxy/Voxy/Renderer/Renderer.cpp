#include "Renderer.h"

#include "RenderCommand.h"

namespace Voxy::Renderer
{
    static Ref<RenderCommand> s_RenderCommand = RenderCommand::Create();
    static Ref<Camera> s_Camera = nullptr;

    void Begin(const Ref<Camera> &camera)
    {
        s_Camera = camera;
    }

    void End()
    {
        s_Camera = nullptr;
    }

    void Submit(const Ref<VertexArray> &va, const Ref<Shader> &shader, const std::string &objectName, size_t count)
    {
        va->Bind();
        shader->Bind();

        VOXY_ASSERT(s_Camera, "Camera cannot be nullptr");
        shader->UploadUniform(s_Camera->GetProjection(), "uProjection");

        auto &obj = va->GetObject(objectName);
        s_RenderCommand->DrawIndexed(obj.IndexCount, obj.Pointer, count);

        va->Unbind();
        shader->Unbind();
    }
}