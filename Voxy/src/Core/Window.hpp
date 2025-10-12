#pragma once

#include <functional>

#include "Events/Event.hpp"
#include "GraphicsContext.hpp"
#include "Helpers.hpp"
#include "Time.hpp"

namespace Voxy {

struct WindowParams {
private:
    using EventCallbackFn = std::function<void(Event &)>;

public:
    const char *title = "Title";
    uint32_t width = 1280;
    uint32_t height = 720;
    Ref<IGraphicsContext> graphicsContext = nullptr;
    EventCallbackFn Callback = nullptr;
};

class IWindow {
public:
    virtual void Update(TimeStep deltaTime) = 0;

    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;
    virtual float GetAspect() const { return GetWidth() / GetHeight(); }

    virtual Ref<IGraphicsContext> GetGraphicsContext() const = 0;

public:
    static Ref<IWindow> Create(WindowParams params = WindowParams());
};

} // namespace Voxy
