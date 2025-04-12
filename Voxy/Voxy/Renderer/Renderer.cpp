#include "Renderer.h"

#include "RenderCommand.h"

namespace Voxy::Renderer
{
    static Ref<RenderCommand> s_RenderCommand = RenderCommand::Create();
    static Ref<Camera> s_Camera = nullptr;
    static Ref<Transform> s_View = nullptr;

    void Begin(const Ref<Camera> &camera, const Ref<Transform> &view)
    {
        s_Camera = camera;
        s_View = view;
    }

    void End()
    {
        s_Camera = nullptr;
        s_View = nullptr;
    }

    void Submit(const Ref<VertexArray> &va, const Ref<Shader> &shader, const std::string &objectName, size_t count)
    {
        va->Bind();
        shader->Bind();

        VOXY_ASSERT(s_Camera, "Camera cannot be nullptr");
        VOXY_ASSERT(s_View, "View cannot be nullptr");
        shader->UploadUniform(s_Camera->GetProjection() * s_View->GetMat(), "uProjection");
        auto &obj = va->GetObject(objectName);
        s_RenderCommand->DrawIndexed(obj.IndexCount, obj.Pointer, count);

        va->Unbind();
        shader->Unbind();
    }
}