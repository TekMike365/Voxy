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

        inline static Ref<spdlog::logger> &GetVoxyLogger() { return m_VoxyLogger; }

    private:
        static Ref<spdlog::logger> m_VoxyLogger;
    };
}

#define VOXY_TRACE(...) Voxy::Log::GetVoxyLogger()->trace(__VA_ARGS__)
#define VOXY_INFO(...) Voxy::Log::GetVoxyLogger()->info(__VA_ARGS__)
#define VOXY_WARN(...) Voxy::Log::GetVoxyLogger()->warn(__VA_ARGS__)
#define VOXY_ERROR(...) Voxy::Log::GetVoxyLogger()->error(__VA_ARGS__)
