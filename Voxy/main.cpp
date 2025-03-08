#include "Log.h"

#include "Voxy.h"
#include "Application.h"

int main()
{
    Voxy::Init();
    Voxy::Application app;
    app.Run();
}