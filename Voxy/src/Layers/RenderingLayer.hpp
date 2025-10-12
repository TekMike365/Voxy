#pragma once

#include "Core/Application.hpp"
#include "Layer.hpp"
#include "Renderer/Renderer.hpp"

namespace Voxy {

class RenderingLayer : public Layer {
    using Renderer = Renderer::Renderer;

public:
    virtual void OnAttach() override {
        m_Renderer = Application::GetInstance()
                         ->GetWindow()
                         ->GetGraphicsContext()
                         ->GetRenderer();
    }

    virtual void OnUpdate(TimeStep deltaTime) override {
        (void)deltaTime;
        m_Renderer->Render();
    }

    virtual const char *GetDebugName() const override {
        return "RenderingLayer";
    }

private:
    Ref<Renderer> m_Renderer;
};

} // namespace Voxy