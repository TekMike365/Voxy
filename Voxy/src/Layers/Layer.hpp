#pragma once

#include "Events/Event.hpp"

namespace Voxy {

class Layer {
public:
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual bool OnEvent(Event &e) { return false; }
};

} // namespace Voxy