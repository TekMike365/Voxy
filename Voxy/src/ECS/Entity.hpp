#pragma once

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <memory>

#include "Helpers.hpp"

namespace Voxy {

class Entity {
    friend class Scene;

public:
    ~Entity() = default;

    template <typename T> void AddComponent(const T &t);
    template <typename T> void RemoveComponent();
    template <typename T> T &GetComponent();

    void Destroy();

private:
    Entity(entt::entity id, Wef<entt::registry> registry)
        : m_ID(id), m_Registry(registry) {}

    Ref<entt::registry> LockRegistry();

private:
    entt::entity m_ID;
    Wef<entt::registry> m_Registry;
};

} // namespace Voxy
