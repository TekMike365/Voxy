#include <Log.hpp>
#include <Test.hpp>

int main(void) {
    SayHello();

    Voxy::Log::Trace("This is amazing!");

    Voxy::Log::Logger l("TestSys");
    l.Info("It werks! :3");
}
