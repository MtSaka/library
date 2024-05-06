#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T>
bool detect_cycle(const Graph<T>& g) {
    const int n = g.size();
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++)
        for (auto& e : g[i]) deg[e]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& e : g[u]) {
            deg[e]--;
            if (deg[e] == 0) q.push(e);
        }
    }
    for (int i = 0; i < n; i++)
        if (deg[i] != 0) return true;
    return false;
}
/**
 * @brief Cycle Detection(閉路検出)
 */