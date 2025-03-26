#pragma once

namespace Voxy
{
    class Timestep
    {
    public:
        Timestep() = default;
        Timestep(float seconds)
            : m_Seconds(seconds) {}
        ~Timestep() = default;

        inline float GetSeconds() const { return m_Seconds; }
        inline float GetMiliseconds() const { return m_Seconds * 1000.0f; }

    private:
        float m_Seconds = 0;
    };
}
