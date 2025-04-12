#pragma once

#include "Layer.h"

namespace Voxy
{
    // TODO: Move render calls here V
    class RenderingLayer : public Layer
    {
    public:
        virtual void OnUpdate(TimeStep dt) override;

        virtual inline const char *GetName() const override { return "Rendering Layer"; }
    };
}
