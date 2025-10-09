#pragma once

#include <functional>

#include "Events/Event.hpp"
#include "Helpers.hpp"

namespace Voxy {

struct WindowParams {
private:
    using EventCallbackFn = std::function<void(Event &)>;

public:
    const char *title = "Title";
    uint32_t width = 1280;
    uint32_t height = 720;
    EventCallbackFn Callback = nullptr;
};

class Window {
public:
    virtual void Update() = 0;

    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;
    virtual float GetAspect() const { return GetWidth() / GetHeight(); }

    virtual void *GetHandle() const = 0;

public:
    static Ref<Window> Create(WindowParams params = WindowParams());
};

} // namespace Voxy
