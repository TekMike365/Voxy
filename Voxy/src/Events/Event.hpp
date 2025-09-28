#pragma once

#include <functional>
#include <string>

namespace Voxy {

enum class EventType { None = 0, WindowCloseEvent, WindowResizeEvent };

#define EVENT_TYPE_DEFS(T)                                                     \
    static EventType GetStaticType() { return EventType::T; }                  \
    virtual EventType GetType() const override { return EventType::T; }

class Event {
public:
    virtual EventType GetType() const { return EventType::None; }
    virtual std::string ToString() const { return "None"; }
};

class EventDispatcher {
public:
    EventDispatcher(Event &e) : m_E(e) {}

    template <typename E> bool Dispatch(std::function<bool(E &)> fn) {
        if (E::GetStaticType() != m_E.GetType())
            return false;
        return fn((E &)m_E);
    }

private:
    Event &m_E;
};

} // namespace Voxy