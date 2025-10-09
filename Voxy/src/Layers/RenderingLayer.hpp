#pragma once

#include "Application.hpp"
#include "Layer.hpp"
#include "Renderer.hpp"

namespace Voxy {

class RenderingLayer : public Layer {
public:
    virtual void OnAttach() override {
        m_Renderer = Application::GetInstance()
                         ->GetWindow()
                         ->GetGraphicsContext()
                         ->GetRenderer();
    }

    virtual void OnUpdate(TimeStep deltaTime) override { m_Renderer->Render(); }

    virtual const char *GetDebugName() const { return "RenderingLayer"; }

private:
    Ref<Renderer> m_Renderer;
};

} // namespace Voxy