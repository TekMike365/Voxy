#include "Setup.hpp"

#include "Log.hpp"
#include "Platform/GLFW/GLFW.hpp"

void Voxy::Init() {
    Log::Init();

    VoxyCoreInfo("Initializing...");

    Platform::GLFW_Init();
}

void Voxy::Terminate() { Platform::GLFW_Terminate(); }
