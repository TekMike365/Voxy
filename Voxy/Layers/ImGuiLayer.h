#pragma once

#include "Layer.h"

namespace Voxy
{
    class ImGuiLayer : public Layer
    {
    public:
        virtual void OnAttach() override;
        virtual void OnUpdate(Timestep dt) override;

        virtual inline const char *GetName() const override { return "Dear ImGui"; }

    private:
        void StartFrame();
    };
}
