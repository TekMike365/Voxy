#pragma once

#include <memory>

template <typename T> using Ref = std::shared_ptr<T>;
template <typename T> using Wef = std::weak_ptr<T>;

#define BIT(x) (1 << x)
