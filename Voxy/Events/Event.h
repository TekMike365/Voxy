#pragma once

#include <functional>

namespace Voxy
{
    enum class EventType
    {
        None = 0,
        WindowClose
    };

#define SET_EVENT_TYPE(T)                                                \
    inline static EventType GetStaticType() { return EventType::T; }     \
    inline virtual EventType GetType() const { return GetStaticType(); } \
    inline virtual const char *GetName() const { return #T; }

    class Event
    {
        friend class EventDispatcher;

    public:
        SET_EVENT_TYPE(None)

    private:
        bool m_Handled = false;
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event &e)
            : m_Event(e) {}
        ~EventDispatcher() = default;

        template <typename E>
        inline void Dispatch(std::function<bool(E &)> fn)
        {
            if (E::GetStaticType() == m_Event.GetType())
                m_Event.m_Handled = fn(static_cast<E &>(m_Event));
        }

    private:
        Event &m_Event;
    };
}
