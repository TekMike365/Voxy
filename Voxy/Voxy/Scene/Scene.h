#pragma once

#include <entt/entt.hpp>

#include "Entity.h"

namespace Voxy
{
    class Scene
    {
    public:
        Scene()
            : m_Registry(std::make_shared<entt::registry>()) {}
        ~Scene() = default;

        inline Entity CreateEntity() { return Entity(m_Registry); }

    private:
        Ref<entt::registry> m_Registry;
    };
}