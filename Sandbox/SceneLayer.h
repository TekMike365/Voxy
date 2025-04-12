#pragma once

#include <Voxy/Layers/Layer.h>
#include <Voxy/Scene/Scene.h>
#include <Voxy/Scene/Components/Camera.h>
#include <Voxy/Scene/Components/Transform.h>

using namespace Voxy;

class SceneLayer : public Layer
{
public:
    SceneLayer() {}
    virtual ~SceneLayer() override {}

    virtual void OnAttach() override
    {
        {
            Entity camera = m_Scene.CreateEntity();
            camera.AddComponent<Camera>();
            auto t = camera.AddComponent<Transform>();
            t.Position.z = -1.0f;
        }
    }

    virtual void OnDetach() override
    {
    }

    virtual void OnUpdate(TimeStep dt) override
    {
        m_Scene.Update(dt);
    }

    virtual bool OnEvent(Event &e) override
    {
        return false;
    }

    virtual inline const char *GetName() const override { return "Scene Layer"; }

private:
    Scene m_Scene;
};
