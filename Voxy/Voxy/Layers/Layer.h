#pragma once

#include "Voxy/Events/Event.h"
#include "Voxy/Timestep.h"

namespace Voxy
{
    class Layer
    {
    public:
        virtual ~Layer() {}

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(Timestep dt) {}
        virtual bool OnEvent(Event &e) { return false; }

        virtual inline const char* GetName() const { return "New Layer"; }
    };
}
