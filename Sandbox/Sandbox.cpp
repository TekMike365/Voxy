#include <Voxy.h>

class Sandbox : public Voxy::Application
{
public:
    Sandbox()
    {
        VOXY_INFO("I am alive!");
    }

    ~Sandbox() {}
};

Voxy::Application *Voxy::CreateApplication()
{
    return new Sandbox();
}
