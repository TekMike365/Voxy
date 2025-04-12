#pragma once

#include <entt/entt.hpp>

#include "Entity.h"
#include "Voxy/TimeStep.h"

namespace Voxy
{
    class Scene
    {
    public:
        Scene();
        ~Scene() = default;

        inline Entity CreateEntity() { return Entity(m_Registry); }

        void Update(TimeStep dt);

    private:
        Ref<entt::registry> m_Registry;
    };
}