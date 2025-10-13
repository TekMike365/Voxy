#pragma once

#include <chrono>

namespace Voxy {

struct TimeStep {
public:
    TimeStep() = default;
    TimeStep(double milisec) : m_Milisec(milisec) {}

    inline float Seconds() const { return m_Milisec / 1000.0f; }
    inline float Miliseconds() const { return m_Milisec; }
    inline float Microseconds() const { return m_Milisec * 1000.0f; }

private:
    double m_Milisec = 0;
};

class Time {
public:
    Time() = default;
    Time(std::chrono::_V2::system_clock::time_point timePoint)
        : m_TimePoint(timePoint) {}

    static inline Time Now() {
        return Time(std::chrono::high_resolution_clock::now());
    }

    inline TimeStep operator-(Time &other) const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   m_TimePoint - other.m_TimePoint)
            .count();
    }

private:
    std::chrono::_V2::system_clock::time_point m_TimePoint;
};

} // namespace Voxy
