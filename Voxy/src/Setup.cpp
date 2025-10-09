#include "Setup.hpp"

#include "Log.hpp"

#include "platform/GLFW/GLFW.hpp"
#include "platform/OpenGL/OpenGL.hpp"

void Voxy::Init() {
    Voxy::Log::Init();

    VoxyCoreInfo("Initializing...");

    Voxy::GLFW_Init();
}

void Voxy::Terminate() {
    Voxy::GLFW_Terminate();
    Voxy::OpenGL_Terminate(); // terminate if it's not terminated
}
