#pragma once
#include "../graph-template.hpp"

template <typename T, typename F>
void enumerate_triangles(const Graph<T>& g, const F& f) {
    // enumerate triangles
    //  O(Msqrt(N))
    const int n = g.size();
    vector<int> deg(n);
    rep(i, n) deg[i] = g[i].size();
    Graph<T> h(n);
    rep(i, n) {
        for (auto& e : g[i]) {
            if (deg[i] < deg[e.to] || (deg[i] == deg[e.to] && i < e.to)) {
                h.add_edge(i, e.to, true, e.cost);
            }
        }
    }
    vector<bool> table(n);
    rep(i, n) {
        for (auto& e : h[i]) table[e.to] = true;
        for (auto& e1 : h[i]) {
            const int j = e1.to;
            for (auto& e2 : h[j]) {
                const int k = e2.to;
                if (table[k]) f(i, j, k);
            }
        }
        for (auto& e : h[i]) table[e.to] = false;
    }
}
/**
 * @brief Enumerate Triangles
 */