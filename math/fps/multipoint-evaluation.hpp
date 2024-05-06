#pragma once
#include "../../template/template.hpp"
#include "fps.hpp"

template <typename T>
vector<T> multipoint_evaluation(const FormalPowerSeries<T>& f, const vector<T>& xs) {
    const int n = xs.size();
    const int sz = 1 << ceil_log2(n);
    vector<FormalPowerSeries<T>> g(sz << 1, {1});
    for (int i = 0; i < n; i++) g[i + sz] = {-xs[i], 1};
    for (int i = sz; i-- > 1;) g[i] = g[i << 1] * g[i << 1 | 1];
    g[1] = f % g[1];
    for (int i = 2; i < sz + n; i++) g[i] = g[i >> 1] % g[i];
    vector<T> res(n);
    for (int i = 0; i < n; i++) res[i] = (g[i + sz].empty() ? T() : g[i + sz][0]);
    return res;
}
/**
 * @brief Multipoint Evaluation(多点評価)
 */