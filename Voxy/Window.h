#pragma once

#include <string>
#include <cstdint>
#include <functional>

#include "Helpers.h"
#include "Events/Event.h"

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
        using CallbackFn = std::function<void(Event &)>;

        virtual void OnUpdate() = 0;

        virtual void SetEventCallback(CallbackFn callback) = 0;

        static Ref<Window> CreateWindow(const WindowParams &params = WindowParams());
    };
}
