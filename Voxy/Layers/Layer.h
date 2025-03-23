#pragma once

#include "Events/Event.h"

namespace Voxy
{
    class Layer
    {
    public:
        virtual ~Layer() {}

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &e) {}

        virtual const char* GetName() const { return "New Layer"; }
    };
}
