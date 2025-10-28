#pragma once

#include <memory>
template <typename T> using Ref = std::shared_ptr<T>;
template <typename T> using Wef = std::weak_ptr<T>;
template <typename T> using URef = std::unique_ptr<T>;

#define RGBto3f(x)                                                             \
    ((float)((x >> 8 * 2) & 0xff) / 0xff), ((float)((x >> 8) & 0xff) / 0xff),  \
        ((float)(x & 0xff) / 0xff)
