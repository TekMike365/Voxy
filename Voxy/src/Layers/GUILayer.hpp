#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Layer.hpp"

namespace Voxy {

class GUILayer : public Layer {
public:
    virtual void OnAttach() override { NewFrame(); }

    virtual void OnUpdate() override {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        NewFrame();
    }

private:
    void NewFrame() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

private:
    bool m_FirstLoop = true;
};

} // namespace Voxy