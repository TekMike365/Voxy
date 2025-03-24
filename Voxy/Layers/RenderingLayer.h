#pragma once

#include "Layer.h"

namespace Voxy
{
    class RenderingLayer : public Layer
    {
    public:
        virtual void OnAttach() override {}
        virtual void OnDetach() override {}
        virtual void OnUpdate(Timestep dt) override;

        virtual inline const char *GetName() const override { return "New Layer"; }
    };
}
