#pragma once

#include "Events/Event.hpp"
#include "Time.hpp"

namespace Voxy {

class ILayer {
public:
    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate(TimeStep deltaTime) {}
    virtual bool OnEvent(Event &e) { return false; }

    virtual const char *GetDebugName() const = 0;
};

} // namespace Voxy