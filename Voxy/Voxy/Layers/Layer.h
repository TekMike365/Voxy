#pragma once

#include "Voxy/Events/Event.h"
#include "Voxy/TimeStep.h"

namespace Voxy
{
    class Layer
    {
    public:
        virtual ~Layer() {}

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(TimeStep dt) {}
        virtual bool OnEvent(Event &e) { return false; }

        virtual inline const char* GetName() const { return "New Layer"; }
    };
}
