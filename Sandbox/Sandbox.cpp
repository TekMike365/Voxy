#include <Voxy.h>

#include "SceneLayer.h"

class Sandbox : public Voxy::Application
{
public:
    Sandbox()
    {
        VOXY_INFO("I am alive!");

        PushLayer(std::make_shared<SceneLayer>());
    }

    ~Sandbox() {}
};

Voxy::Application *Voxy::CreateApplication()
{
    return new Sandbox();
}
