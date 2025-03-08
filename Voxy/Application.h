#pragma once

#include <GLFW/glfw3.h>

#include "Helpers.h"

namespace Voxy
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        GLFWwindow *m_Window;
    };
}
