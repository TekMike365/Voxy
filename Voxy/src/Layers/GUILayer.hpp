#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Layer.hpp"

namespace Voxy {

class GUILayer : public Layer {
public:
    virtual void OnAttach() override { NewFrame(); }

    virtual void OnUpdate(TimeStep deltaTime) override {
        (void)deltaTime;

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        NewFrame();
    }

    virtual const char *GetDebugName() const override { return "GUILayer"; }

private:
    void NewFrame() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
};

} // namespace Voxy