#include "Log.hpp"

namespace Voxy::Log {

Ref<spdlog::logger> g_CoreLogger = nullptr;
Ref<spdlog::logger> g_Logger = nullptr;

void Init() {
    g_CoreLogger = spdlog::stdout_color_mt("CORE");
    g_CoreLogger->set_level(spdlog::level::trace);
    g_CoreLogger->set_pattern("[%X.%e] [\x1b[36m%n\x1b[39;49m] %^(%l)%$ %v");

    g_Logger = spdlog::stdout_color_mt("APP");
    g_Logger->set_level(spdlog::level::trace);
    g_Logger->set_pattern("[%X.%e] [\x1b[33m%n\x1b[39;49m] %^(%l)%$ %v");

    Info("Logger initialized.");
}

} // namespace Voxy::Log
