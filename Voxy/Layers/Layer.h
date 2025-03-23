#pragma once

#include "Events/Event.h"
#include "Timestep.h"

namespace Voxy
{
    class Layer
    {
    public:
        virtual ~Layer() {}

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(Timestep dt) {}
        virtual void OnEvent(Event &e) {}

        virtual const char* GetName() const { return "New Layer"; }
    };
}
