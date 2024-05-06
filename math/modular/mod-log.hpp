#pragma once
#include "../../ds/others/hash-map.hpp"
#include "../../template/template.hpp"

template <typename T>
T discrete_logarithm(T x, T y, T m) {
    x %= m, y %= m;
    if (y == 1 || m == 1) return 0;
    if (x == 0) return y == 0 ? 1 : -1;
    T add = 0, g, k = 1 % m;
    while ((g = gcd(x, m)) > 1) {
        if (y == k) return add;
        if (y % g) return -1;
        y /= g, m /= g, add++;
        k = (k * (x / g)) % m;
    }
    T n = sqrt(m) + 1;
    T tmp = mod_pow(x, n, m);
    HashMap<T, T> mp;
    for (T i = 0, now = y; i <= n; i++) {
        mp[now] = i;
        now = (now * x) % m;
    }
    for (T i = 1, now = k; i <= n; i++) {
        now = (now * tmp) % m;
        if (mp.contain(now)) return n * i - mp[now] + add;
    }
    return -1;
}
/**
 * @brief Mod Log(離散対数)
 */