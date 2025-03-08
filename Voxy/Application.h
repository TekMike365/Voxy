#pragma once

#include "Helpers.h"
#include "Window.h"

namespace Voxy
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        Ref<Window> m_Window;
    };
}
