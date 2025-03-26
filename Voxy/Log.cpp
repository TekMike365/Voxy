#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Voxy
{
    Ref<spdlog::logger> Log::m_CoreLogger;
    Ref<spdlog::logger> Log::m_ClientLogger;

    void Voxy::Log::Init()
    {
        m_CoreLogger = spdlog::stdout_color_mt("Voxy");
        m_CoreLogger->set_level(spdlog::level::trace);
        m_CoreLogger->set_pattern("[%X] [\e[96m%n\e[39;49m] %^[%l]%$: %v");

        m_ClientLogger = spdlog::stdout_color_mt("Client");
        m_ClientLogger->set_level(spdlog::level::trace);
        m_ClientLogger->set_pattern("[%X] [\e[33m%n\e[39;49m] %^[%l]%$: %v");

        m_CoreLogger->info("Initialized logger!");
    }
}
