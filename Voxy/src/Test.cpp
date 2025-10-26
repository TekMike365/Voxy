#include "Test.hpp"

#include <iostream>

#include "Log.hpp"

void SayHello() {
    printf("Hello, World!\n");
    Voxy::Log::Init();

    Voxy::Log::Logger l("TestSys");
    l.Info("Say hello! {}", "<3");
}
