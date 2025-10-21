#pragma once

#include <entt/entt.hpp>

#include "Entity.hpp"
#include "Helpers.hpp"

namespace Voxy {

class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    Entity CreateEntity();
    void DestroyEntity(Entity &e);

private:
    Ref<entt::registry> m_Registry;
};

} // namespace Voxy
