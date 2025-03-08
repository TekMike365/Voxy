#include "Log.h"

#include "Application.h"

int main()
{
    Voxy::Log::Init();

    Voxy::Application app;
    app.Run();
}