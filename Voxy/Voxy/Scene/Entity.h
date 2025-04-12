#pragma once

#include <entt/entt.hpp>

#include "Helpers.h"
#include "Log.h"

namespace Voxy
{
    class Entity
    {
    public:
        Entity(const Ref<entt::registry> &registry)
            : m_Registry(registry)
        {
            auto reg = m_Registry.lock();
            VOXY_ASSERT(reg, "Registry doesn't exist");
            m_Entity = reg->create();
        }

        Entity(entt::entity entity, const Ref<entt::registry> &registry)
            : m_Entity(entity), m_Registry(registry)
        {
            VOXY_ASSERT(!m_Registry.expired(), "Registry doesn't exist");
        }

        template <typename C, typename... Args>
        inline C &AddComponent(Args &&...args)
        {
            auto reg = m_Registry.lock();
            VOXY_ASSERT(reg, "Registry doesn't exist");
            reg->emplace<C>(m_Entity, std::forward<Args>(args)...);
            return GetComponent<C>();
        }

        template <typename C>
        inline C &GetComponent()
        {
            auto reg = m_Registry.lock();
            VOXY_ASSERT(reg, "Registry doesn't exist");
            return reg->get<C>(m_Entity);
        }

        template <typename C>
        inline bool HasComponent() const
        {
            auto reg = m_Registry.lock();
            VOXY_ASSERT(reg, "Registry doesn't exist");
            return reg->all_of<C>(m_Entity);
        }

    private:
        entt::entity m_Entity;
        Wef<entt::registry> m_Registry;
    };
}
