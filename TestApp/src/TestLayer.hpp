#pragma once

#include <imgui.h>

#include <Layers/Layer.hpp>

#include <Renderer/Buffer.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Shader.hpp>
#include <Renderer/VertexArray.hpp>

#include <ECS/Transform.hpp>

using namespace Voxy; // -_(:3)_-

class TestLayer : public Layer {
public:
    virtual void OnAttach() override { SetupDemo(); }

    virtual void OnUpdate(TimeStep deltaTime) override { m_DT = deltaTime; }

    virtual void OnRender() override {
        // ImGui::ShowDemoWindow();
        DisplayOverlay();
        RenderDemo();
    }

    virtual const char *GetDebugName() const override { return "TestLayer"; }

private:
    void DisplayOverlay();
    void SetupDemo();
    void RenderDemo();

private:
    TimeStep m_DT = 0;

private:
    Ref<Renderer::VertexArray> m_VertexArray;
    Ref<Renderer::Shader> m_Shader;
    Ref<Renderer::Renderer> m_Renderer;

    Ref<Renderer::Buffer> m_VertexBuffer;
    Ref<Renderer::Buffer> m_IndexBuffer;
    Ref<Renderer::Buffer> m_OffsetsBuffer;

    Transform m_Transform;
};
