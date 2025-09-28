#pragma once

#include "Events/Event.hpp"
#include "Events/WindowEvents.hpp"
#include "Layer.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Voxy {

class GUILayer : public Layer {
public:
    virtual void OnUpdate() override {
        if (m_FirstLoop)
            m_FirstLoop = false;
        else
            ImGui::Render();
        ImGui::NewFrame();
    }

private:
    bool m_FirstLoop = true;
};

} // namespace Voxy