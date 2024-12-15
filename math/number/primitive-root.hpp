#pragma once
#include "../../template/template.hpp"
#include "../modular/montgomery-modint.hpp"
#include "miller-rabin.hpp"
#include "pollard-rho.hpp"

template <typename T = MontgomeryModInt<ull, -4>, typename Rand = Random64>
ull primitive_root(ull n, Rand rand = rand64) {
    assert(is_prime_fast(n));
    if (n == 2) return 1;
    if (T::get_mod() != n) T::set_mod(n);
    auto divs = factorize(n - 1);
    divs.erase(unique(divs.begin(), divs.end()), divs.end());
    for (auto& x : divs) x = (n - 1) / x;
    const T e = 1;
    while (1) {
        ull g = rand.uniform(2ull, n - 1);
        bool ok = 1;
        for (auto x : divs) {
            if (T(g).pow(x) == e) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <ull p, enable_if_t<is_prime_v<p>>* = nullptr>
constexpr ull constexpr_primitive_root() {
    if constexpr (p == 2) return 1;
    if constexpr (p == 167772161) return 3;
    if constexpr (p == 469762049) return 3;
    if constexpr (p == 754974721) return 11;
    if constexpr (p == 998244353) return 3;
    if constexpr (p == 1224736769) return 3;
    if constexpr (p == 1811939329) return 11;
    if constexpr (p == 2013265921) return 11;
    rep(g, 2, p) {
        if (mod_pow(g, (p - 1) >> 1, p) != 1) return g;
    }
    return -1;
}
/**
 * @brief Primitive Root(原始根)
 */