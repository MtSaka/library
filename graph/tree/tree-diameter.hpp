#pragma once
#include "../graph-template.hpp"
template <typename T = UnweightedEdge>
struct TreeDiameter : Graph<T> {
    using Graph<T>::g;
    Edges<T> path;
    T build() {
        to.assign(g.size(), -1);
        auto p = dfs(0, -1);
        auto q = dfs(p.second, -1);
        int now = p.second;
        while (now != q.second) {
            for (auto& e : g[now]) {
                if (to[now] == e.to) path.emplace_back(e);
            }
            now = to[now];
        }
        return q.first;
    }
    TreeDiameter() {}
    TreeDiameter(int n) : Graph<T>(n) {}
    TreeDiameter(const Graph<T>& g) : Graph<T>(g) {}

   private:
    vector<int> to;
    pair<T, int> dfs(int idx, int par) {
        pair<T, int> res(0, idx);
        for (auto& e : g[idx])
            if (e.to != par) {
                auto cost = dfs(e.to, idx);
                cost.first += e.cost;
                if (res < cost) res = cost, to[idx] = e.to;
            }
        return res;
    }
};
/**
 * @brief Tree Diameter(木の直径)
 */