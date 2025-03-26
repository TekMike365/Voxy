#pragma once

#include <memory>
#include <spdlog/spdlog.h>

#include "Helpers.h"

namespace Voxy
{
    class Log
    {
    public:
        static void Init();

        inline static Ref<spdlog::logger> &GetCoreVoxyLogger() { return m_CoreLogger; }
        inline static Ref<spdlog::logger> &GetClientVoxyLogger() { return m_ClientLogger; }

    private:
        static Ref<spdlog::logger> m_CoreLogger;
        static Ref<spdlog::logger> m_ClientLogger;
    };
}

#define VOXY_CORE_TRACE(...) Voxy::Log::GetCoreVoxyLogger()->trace(__VA_ARGS__)
#define VOXY_CORE_INFO(...) Voxy::Log::GetCoreVoxyLogger()->info(__VA_ARGS__)
#define VOXY_CORE_WARN(...) Voxy::Log::GetCoreVoxyLogger()->warn(__VA_ARGS__)
#define VOXY_CORE_ERROR(...) Voxy::Log::GetCoreVoxyLogger()->error(__VA_ARGS__)

#define VOXY_TRACE(...) Voxy::Log::GetClientVoxyLogger()->trace(__VA_ARGS__)
#define VOXY_INFO(...) Voxy::Log::GetClientVoxyLogger()->info(__VA_ARGS__)
#define VOXY_WARN(...) Voxy::Log::GetClientVoxyLogger()->warn(__VA_ARGS__)
#define VOXY_ERROR(...) Voxy::Log::GetClientVoxyLogger()->error(__VA_ARGS__)

