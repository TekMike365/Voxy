#pragma once

#include <memory>
#include <spdlog/spdlog.h>

#include "Helpers.hpp"

namespace Voxy {

class Log {
public:
    static void Init();

    inline static Ref<spdlog::logger> &GetCoreLogger() { return m_CoreLogger; }
    inline static Ref<spdlog::logger> &GetClientLogger() {
        return m_ClientLogger;
    }

private:
    static Ref<spdlog::logger> m_CoreLogger;
    static Ref<spdlog::logger> m_ClientLogger;
};

} // namespace Voxy

#define VoxyCoreTrace(...) Voxy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VoxyCoreInfo(...) Voxy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VoxyCoreWarn(...) Voxy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VoxyCoreError(...) Voxy::Log::GetCoreLogger()->error(__VA_ARGS__)

#define VoxyTrace(...) Voxy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VoxyInfo(...) Voxy::Log::GetClientLogger()->info(__VA_ARGS__)
#define VoxyWarn(...) Voxy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VoxyError(...) Voxy::Log::GetClientLogger()->error(__VA_ARGS__)

#define VoxyAssert(x, ...)                                                     \
    if (!(x)) {                                                                \
        VoxyCoreError(__VA_ARGS__);                                            \
        assert(0);                                                             \
    }
