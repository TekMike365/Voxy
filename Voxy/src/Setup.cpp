#include "Setup.hpp"

#include "Log.hpp"
#include "platform/GLFW/GLFW.hpp"

void Voxy::Init() {
    Voxy::Log::Init();

    VoxyCoreInfo("Initializing");

    Voxy::Platform::GLFW_Init();
}

void Voxy::Terminate() { Voxy::Platform::GLFW_Terminate(); }
