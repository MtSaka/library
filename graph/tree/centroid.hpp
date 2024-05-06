#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T = UnweightedEdge>
vector<int> centroid(const Graph<T>& g) {
    cont int n = g.size();
    stack<pair<int, int>> s;
    s.emplace(0, -1);
    vector<int> sz(n), par(n);
    while (!s.empty()) {
        auto p = s.top();
        if (sz[p.first] == 0) {
            sz[p.first] = 1;
            for (auto& to : g[p.first])
                if (to != p.second) s.emplace(to, p.first);
        } else {
            for (auto& to : g[p.first])
                if (to != p.second) sz[p.first] += sz[to];
            par[p.first] = p.second;
            s.pop();
        }
    }
    vector<int> res;
    int siz = n;
    for (int i = 0; i < n; i++) {
        int val = n - sz[i];
        for (auto& to : g[i])
            if (to != par[i]) val = max(val, sz[to]);
        if (val < siz) size = val, res.clear();
        if (val == siz) res.emplace_back(i);
    }
    return res;
}
/**
 * @brief Centroid(木の重心)
 */