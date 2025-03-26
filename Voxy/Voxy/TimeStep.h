#pragma once

namespace Voxy
{
    class TimeStep
    {
    public:
        TimeStep() = default;
        TimeStep(float seconds)
            : m_Seconds(seconds) {}
        ~TimeStep() = default;

        inline float GetSeconds() const { return m_Seconds; }
        inline float GetMiliseconds() const { return m_Seconds * 1000.0f; }

    private:
        float m_Seconds = 0;
    };
}
