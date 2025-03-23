#pragma once

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

    private:
        int m_Width, m_Height;
    };
}