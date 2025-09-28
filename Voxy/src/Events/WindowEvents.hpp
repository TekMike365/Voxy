#pragma once

#include "Event.hpp"

namespace Voxy {

class WindowCloseEvent : public Event {
public:
    EVENT_TYPE_DEFS(WindowCloseEvent)

    virtual std::string ToString() const override { return "WindowCloseEvent"; }
};

} // namespace Voxy