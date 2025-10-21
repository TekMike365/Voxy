#include "Entity.hpp"

#include "Log.hpp"

#include "Transform.hpp"

namespace Voxy {

void Entity::Destroy() {
    auto registry = LockRegistry();
    registry->destroy(m_ID);
    m_ID = entt::null;
}

/*
    Add/Remove/GetComponent Generic
*/

template <typename T> void Entity::AddComponent(const T &t) {
    auto registry = LockRegistry();

    if (registry->any_of<T>(m_ID)) {
        VoxyCoreWarn("ECS: multiple assignment of a component to entity ({})",
                     m_ID);
        return;
    }

    registry->emplace<T>(m_ID, t);
}

template <typename T> void Entity::RemoveComponent() {
    auto registry = LockRegistry();

    if (!registry->any_of<T>(m_ID)) {
        VoxyCoreWarn(
            "ECS: removeal of a non-existing component from entity ({})", m_ID);
        return;
    }

    registry->remove<T>(m_ID);
}

template <typename T> T &Entity::GetComponent() {
    auto registry = LockRegistry();

    if (!registry->any_of<T>(m_ID)) {
        VoxyCoreWarn(
            "ECS: retrieval of non-existing component from entity ({})", m_ID);
        return;
    }
    return registry->get<T>(m_ID);
}

Ref<entt::registry> Entity::LockRegistry() {
    if (!m_Registry.expired()) {
        VoxyCoreWarn("ECS: Tried to destroy entity in a non-existing scene.");
        return nullptr;
    }

    auto registry = m_Registry.lock();

    if (!registry->valid(m_ID)) {
        VoxyCoreWarn("ECS: Tried to destroy a non-existing entity.");
        return nullptr;
    }

    return registry;
}

} // namespace Voxy
