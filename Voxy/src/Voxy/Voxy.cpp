#include "Voxy.hpp"

#include "ImGuiManager.hpp"
#include "Log.hpp"
#include "Platform/Platform.hpp"

void Voxy::Init() {
    Log::Init();
    Platform::Init();
    ImGuiManager::Init();
}

void Voxy::Terminate() {
    ImGuiManager::Terminate();
    Platform::Terminate();
}
