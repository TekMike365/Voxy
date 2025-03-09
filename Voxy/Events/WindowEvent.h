#pragma once

#include "Event.h"

namespace Voxy
{
    class WindowCloseEvent : public Event
    {
    public:
        SET_EVENT_TYPE(WindowClose)
    };
}