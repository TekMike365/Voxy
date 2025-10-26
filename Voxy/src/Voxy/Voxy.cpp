#include "Voxy.hpp"

#include "Log.hpp"
#include "Platform/Platform.hpp"

void Voxy::Init() {
    Log::Init();
    Platform::Init();
}

void Voxy::Terminate() { Platform::Terminate(); }
