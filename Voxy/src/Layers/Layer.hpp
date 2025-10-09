#pragma once

#include "Events/Event.hpp"
#include "Time.hpp"

namespace Voxy {

class Layer {
public:
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate(TimeStep deltaTime) {}
    virtual bool OnEvent(Event &e) { return false; }
};

} // namespace Voxy