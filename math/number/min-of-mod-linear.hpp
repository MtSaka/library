#pragma once

#include "../../template/template.hpp"
#include "floor-sum.hpp"

template <typename T>
T min_of_mod_linear(T n, T m, T a, T b) {
    if ((a %= m) < 0) a += m;
    if ((b %= m) < 0) b += m;
    T l = 0, r = m;
    const T fl = floor_sum(n, m, a, b);
    while (r - l > 1) {
        T mid = (l + r) / 2;
        if (floor_sum(n, m, a, b - mid) == fl)
            l = mid;
        else
            r = mid;
    }
    return l;
}

/**
 * @brief Min of Mod of Linear
 */