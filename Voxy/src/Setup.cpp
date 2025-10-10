#include "Setup.hpp"

#include "Log.hpp"
#include "Platform/GLFW/GLFW.hpp"

void Voxy::Init() {
    Log::Init();

    VoxyCoreInfo("Initializing...");

    Platform::GLFW::Init();
}

void Voxy::Terminate() { Platform::GLFW::Terminate(); }
