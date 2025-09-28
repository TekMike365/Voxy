#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Setup.hpp"

int main(void) {
    Voxy::Init();

    Voxy::Application app;
    app.Run();

    Voxy::Terminate();
}
