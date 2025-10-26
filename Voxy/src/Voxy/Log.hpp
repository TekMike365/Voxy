#pragma once

#include "Helpers.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Voxy::Log {

#ifndef VOXY_CORE
extern Ref<spdlog::logger> g_Logger;
#define VOXY_LOGGER g_Logger
#else // ifndef VOXY_CORE
extern Ref<spdlog::logger> g_CoreLogger;
#define VOXY_LOGGER g_CoreLogger
void Init();
#endif // ifndef VOXY_CORE

template <typename... Args>
static inline void Trace(const std::string &fmt, Args &&...args) {
    VOXY_LOGGER->trace(fmt::runtime(fmt), std::forward<Args>(args)...);
}

template <typename... Args>
static inline void Info(const std::string &fmt, Args &&...args) {
    VOXY_LOGGER->info(fmt::runtime(fmt), std::forward<Args>(args)...);
}

template <typename... Args>
static inline void Warn(const std::string &fmt, Args &&...args) {
    VOXY_LOGGER->warn(fmt::runtime(fmt), std::forward<Args>(args)...);
}

template <typename... Args>
static inline void Error(const std::string &fmt, Args &&...args) {
    VOXY_LOGGER->error(fmt::runtime(fmt), std::forward<Args>(args)...);
}

class Logger {
public:
    Logger(const std::string &name)
        : _prefix("\x1b[35m" + name + ": \x1b[39;49m") {}

    template <typename... Args>
    inline void Trace(const std::string &fmt, Args &&...args) const {
        Log::Trace(_prefix + fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void Info(const std::string &fmt, Args &&...args) const {
        Log::Info(_prefix + fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void Warn(const std::string &fmt, Args &&...args) const {
        Log::Warn(_prefix + fmt, std::forward<Args>(args)...);
    }

    template <typename... Args>
    inline void Error(const std::string &fmt, Args &&...args) const {
        Log::Error(_prefix + fmt, std::forward<Args>(args)...);
    }

private:
    const std::string _prefix;
};

} // namespace Voxy::Log
