#pragma once

#include <string>
#include <cstdint>
#include <functional>

#include "Log.h"
#include "Helpers.h"
#include "Events/Event.h"

namespace Voxy
{
    class GraphicsContext;

    struct WindowParams
    {
        uint32_t Width = 1080;
        uint32_t Height = 720;
        std::string Title = "Voxy";
    };

    class Window
    {
    public:
        using CallbackFn = std::function<void(Event &)>;

        virtual void OnUpdate() = 0;

        virtual void SetEventCallback(CallbackFn callback) = 0;

        virtual void *GetWindowHandle() const = 0;
        virtual const WindowParams &GetParams() const = 0;

        static Ref<Window> Create(const WindowParams &params = WindowParams());
    };
}
