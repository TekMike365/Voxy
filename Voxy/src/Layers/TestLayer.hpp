#pragma once

#include <imgui.h>

#include "Layer.hpp"

#include "Renderer/Buffer.hpp"
#include "Renderer/Mesh.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/Shader.hpp"

namespace Voxy {

class TestLayer : public Layer {
public:
    virtual void OnAttach() override { SetupDemo(); }

    virtual void OnDetach() override {}

    virtual void OnUpdate(TimeStep deltaTime) override {
        // ImGui::ShowDemoWindow();
        DisplayOverlay(deltaTime);
        RenderDemo(deltaTime);
    }

    virtual bool OnEvent(Event &e) override {
        (void)e;
        return false;
    }

    virtual const char *GetDebugName() const override { return "TestLayer"; }

private:
    void DisplayOverlay(TimeStep deltaTime);
    void SetupDemo();
    void RenderDemo(TimeStep deltaTime);

private:
    Ref<Renderer::Mesh> m_Mesh;
    Ref<Renderer::Shader> m_Shader;
    Ref<Renderer::Renderer> m_Renderer;

    Ref<Renderer::Buffer> m_VertexBuffer;
    Ref<Renderer::Buffer> m_IndexBuffer;
    Ref<Renderer::Buffer> m_OffsetsBuffer;
};

} // namespace Voxy
