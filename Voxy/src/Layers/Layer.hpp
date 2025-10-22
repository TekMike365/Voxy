#pragma once

#include "Events/Event.hpp"
#include "Time.hpp"

namespace Voxy {

class Layer {
public:
    virtual ~Layer() = default;

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual bool OnEvent(Event &e) {
        (void)e;
        return false;
    }
    virtual void OnUpdate(TimeStep deltaTime) { (void)deltaTime; }
    virtual void OnRender() {}

    virtual const char *GetDebugName() const = 0;
};

} // namespace Voxy