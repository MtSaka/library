#pragma once
#include "../../template/template.hpp"
#include "../others/combinatorics.hpp"
#include "fps.hpp"

template <typename T, typename Comb = Combinatorics<T>>
FormalPowerSeries<T> taylor_shift(FormalPowerSeries<T> f, const T& a) {
    const int n = f.size();
    Comb::extend(n);
    for (int i = 0; i < n; i++) f[i] *= Comb::fac(i);
    reverse(f.begin(), f.end());
    FormalPowerSeries<T> g(n, 1);
    for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * Comb::fac(i - 1) * Comb::finv(i);
    f *= g;
    f.resize(n);
    reverse(f.begin(), f.end());
    for (int i = 0; i < n; i++) f[i] *= Comb::finv(i);
    return f;
}
/**
 * @brief Taylor Shift(多項式の平行移動)
 */