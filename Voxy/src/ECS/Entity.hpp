#pragma once

#include <entt/entt.hpp>
#include <glm/glm.hpp>
#include <memory>

#include "Helpers.hpp"
#include "Log.hpp"

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

template <typename T> inline void Entity::AddComponent(const T &t) {
    auto registry = LockRegistry();

    if (registry->any_of<T>(m_ID)) {
        VoxyCoreWarn("ECS: multiple assignment of a component to entity ({})",
                     m_ID);
        return;
    }

    registry->emplace<T>(m_ID, t);
}

template <typename T> inline void Entity::RemoveComponent() {
    auto registry = LockRegistry();

    if (!registry->any_of<T>(m_ID)) {
        VoxyCoreWarn(
            "ECS: removeal of a non-existing component from entity ({})", m_ID);
        return;
    }

    registry->remove<T>(m_ID);
}

template <typename T> inline T &Entity::GetComponent() {
    auto registry = LockRegistry();

    if (!registry->any_of<T>(m_ID)) {
        VoxyCoreWarn(
            "ECS: retrieval of non-existing component from entity ({})", m_ID);
        return;
    }
    return registry->get<T>(m_ID);
}

} // namespace Voxy
