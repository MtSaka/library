#pragma once
#include "../../template/template.hpp"
#include "fps.hpp"

template <typename T>
FormalPowerSeries<T> polynomial_interpolation(const vector<T>& xs, const vector<T>& ys) {
    const int n = xs.size();
    const int sz = 1 << ceil_log2(n);
    vector<FormalPowerSeries<T>> mul(sz << 1, {1});
    for (int i = 0; i < n; i++) mul[i + sz] = {-xs[i], T(1)};
    for (int i = sz; i-- > 1;) mul[i] = mul[i << 1] * mul[i << 1 | 1];
    vector<FormalPowerSeries<T>> g(2 * sz);
    g[1] = mul[1].diff() % mul[1];
    for (int i = 2; i < sz + n; i++) g[i] = g[i >> 1] % mul[i];
    for (int i = 0; i < n; i++) g[sz + i] = {ys[i] / g[sz + i][0]};
    for (int i = sz; i-- > 1;) g[i] = g[i << 1] * mul[i << 1 | 1] + g[i << 1 | 1] * mul[i << 1];
    return g[1];
}
/**
 * @brief Polynomial Interpolation(多項式補間)
 */