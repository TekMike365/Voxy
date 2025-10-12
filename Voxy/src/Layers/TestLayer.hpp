#pragma once

#include <imgui.h>

#include "Layer.hpp"

namespace Voxy {

class TestLayer : public ILayer {
public:
    virtual void OnAttach() override {}

    virtual void OnDetach() override {}

    virtual void OnUpdate(TimeStep deltaTime) override {
        ImGui::ShowDemoWindow();
        DisplayOverlay(deltaTime);
    }

    virtual bool OnEvent(Event &e) override { return false; }

    virtual const char *GetDebugName() const { return "TestLayer"; }

private:
    void DisplayOverlay(TimeStep deltaTime) {
        const ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImVec2 workPos = viewport->WorkPos; // Top-left
        ImVec2 workSize = viewport->WorkSize;

        ImVec2 windowPos =
            ImVec2(workPos.x + workSize.x, workPos.y); // Top-right
        ImVec2 windowPosPivot = ImVec2(1.0f, 0.0f);    // Top-right

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always, windowPosPivot);
        ImGui::SetNextWindowBgAlpha(0.65f);

        ImGuiWindowFlags windowFlags =
            ImGuiWindowFlags_NoDecoration |     // No title bar, resize borders,
                                                // etc.
            ImGuiWindowFlags_AlwaysAutoResize | // Window size adjusts to
                                                // content
            ImGuiWindowFlags_NoSavedSettings |  // Don't save settings (pos,
                                                // size) to the ini file
            ImGuiWindowFlags_NoFocusOnAppearing | // Don't steal focus
            ImGuiWindowFlags_NoNav | // Disable keyboard/gamepad navigation
            ImGuiWindowFlags_NoMove;

        ImGui::Begin("Overlay", nullptr, windowFlags);
        ImGui::Text("Frame: %.3f ms (%.1f FPS)", deltaTime.Miliseconds(),
                    1.0f / deltaTime.Seconds());
        ImGui::End();
    }
};

} // namespace Voxy
