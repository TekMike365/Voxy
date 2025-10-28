#include "ImGuiManager.hpp"

#include "Log.hpp"
#include "Platform/Platform.hpp"
#include <imgui.h>

namespace Voxy {

URef<ImGuiManager> ImGuiManager::s_Instance = nullptr;

void ImGuiManager::Init() {
    if (s_Instance)
        assert(0);
    s_Instance = std::make_unique<ImGuiManager>();

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |=
        ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    Log::Info("Dear ImGui context created.");
}

void ImGuiManager::Terminate() {
    ImGui::DestroyContext();
    Log::Info("Dear ImGui context destroyed.");
}

void ImGuiManager::BeginFrame() {
    Platform::BeginImGuiFrame();
    ImGui::NewFrame();
}

void ImGuiManager::EndFrame() { ImGui::Render(); }

ImDrawData *ImGuiManager::GetDrawData() { return ImGui::GetDrawData(); }

} // namespace Voxy
