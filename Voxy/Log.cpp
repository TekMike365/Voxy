#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Voxy
{
    Ref<spdlog::logger> Log::m_VoxyLogger;

    void Voxy::Log::Init()
    {
        m_VoxyLogger = spdlog::stdout_color_mt("Voxy");
        m_VoxyLogger->set_level(spdlog::level::trace);
        m_VoxyLogger->set_pattern("[%X] [%n] %^[%l]%$: %v");

        m_VoxyLogger->info("Initialised logger!");
    }
}
