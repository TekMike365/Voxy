#pragma once

#include <string>
#include <cstdint>

#include "Helpers.h"

namespace Voxy
{
    struct WindowParams
    {
        uint32_t Width = 1024;
        uint32_t Height = 720;
        std::string Title = "Voxy";
    };

    class Window
    {
    public:

        virtual void OnUpdate() = 0;

        // TODO: Move (Create Events)
        virtual bool ShouldClose() = 0;

        static Ref<Window> CreateWindow(const WindowParams &params = WindowParams());
    };
}
