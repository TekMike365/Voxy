#include "ImGuiLayer.h"

#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

namespace Voxy
{
    void ImGuiLayer::OnAttach()
    {
        StartFrame();
    }

    void ImGuiLayer::OnUpdate(TimeStep dt)
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        StartFrame();
    }

    void ImGuiLayer::StartFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }
}
