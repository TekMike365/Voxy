#pragma once

#include "Event.hpp"
#include <cstdint>
#include <format>

namespace Voxy {

class WindowCloseEvent : public Event {
public:
    EVENT_TYPE_DEFS(WindowCloseEvent)

    virtual std::string ToString() const override { return "WindowCloseEvent"; }
};

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(uint32_t width, uint32_t height)
        : m_Width(width), m_Height(height) {}

    EVENT_TYPE_DEFS(WindowResizeEvent)

    virtual std::string ToString() const override {
        return std::format("WindowResizeEvent ({}, {})", m_Width, m_Height);
    }

private:
    uint32_t m_Width;
    uint32_t m_Height;
};

} // namespace Voxy