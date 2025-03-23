#pragma once

#include <sstream>

#include "Event.h"

namespace Voxy
{
    class WindowCloseEvent : public Event
    {
    public:
        SET_EVENT_TYPE(WindowClose)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(int width, int height)
            : m_Width(width), m_Height(height) {}

        inline int GetWidth() const { return m_Width; }
        inline int GetHeight() const { return m_Height; }

        SET_EVENT_TYPE(WindowResize)

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << GetName() << "[" << m_Width << ", " << m_Height << "](w, h)";
            return ss.str();
        }

    private:
        int m_Width, m_Height;
    };
}