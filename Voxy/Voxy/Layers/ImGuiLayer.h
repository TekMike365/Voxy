#pragma once

#include "Layer.h"

namespace Voxy
{
    class ImGuiLayer : public Layer
    {
    public:
        virtual void OnAttach() override;
        virtual void OnUpdate(TimeStep dt) override;

        virtual inline const char *GetName() const override { return "Dear ImGui Layer"; }

    private:
        void StartFrame();
    };
}
