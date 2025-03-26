#include <Voxy.h>

class Sandbox : public Voxy::Application
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

Voxy::Application *Voxy::CreateApplication()
{
    return new Sandbox();
}
