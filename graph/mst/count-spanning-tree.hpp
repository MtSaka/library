#pragma once

#include "../graph-template.hpp"
#include "../../math/others/matrix.hpp"

template <typename T, typename U>
T count_spanning_tree(const Graph<U>& g, int v = 0) {
    const int n = g.size();
    Matrix<T> a(n - 1, n - 1);
    rep(i, n) {
        if (i == v) continue;
        T cnt = 0;
        for (const auto& e : g[i])
            if (e.to != i) cnt += e.cost;
        a[i < v ? i : i - 1][i < v ? i : i - 1] = cnt;
    }
    rep(i, n) if (i != v) {
        for (const auto& e : g[i]) {
            if (e.to == v || e.to == i) continue;
            a[i < v ? i : i - 1][e.to < v ? e.to : e.to - 1] -= e.cost;
        }
    }
    return a.determinant();
}