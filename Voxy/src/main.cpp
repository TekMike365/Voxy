#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Log.hpp"
#include "platform/GLFW/GLFW.hpp"

int main(void) {
    Voxy::Log::Init();
    VoxyCoreInfo("Initialized logger.");
    Voxy::Platform::GLFW_Init();

    Voxy::Application app;
    app.Run();

    Voxy::Platform::GLFW_Terminate();
}
