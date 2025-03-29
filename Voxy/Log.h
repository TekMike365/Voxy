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

        inline static Ref<spdlog::logger> &GetCoreLogger() { return m_CoreLogger; }
        inline static Ref<spdlog::logger> &GetClientLogger() { return m_ClientLogger; }

    private:
        static Ref<spdlog::logger> m_CoreLogger;
        static Ref<spdlog::logger> m_ClientLogger;
    };
}

#define VOXY_CORE_TRACE(...) Voxy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VOXY_CORE_INFO(...) Voxy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VOXY_CORE_WARN(...) Voxy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VOXY_CORE_ERROR(...) Voxy::Log::GetCoreLogger()->error(__VA_ARGS__)

#define VOXY_TRACE(...) Voxy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VOXY_INFO(...) Voxy::Log::GetClientLogger()->info(__VA_ARGS__)
#define VOXY_WARN(...) Voxy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VOXY_ERROR(...) Voxy::Log::GetClientLogger()->error(__VA_ARGS__)

#define VOXY_ASSERT(x, ...)           \
    if (!(x))                           \
    {                                 \
        VOXY_CORE_ERROR(__VA_ARGS__); \
        assert(0);                    \
    }
