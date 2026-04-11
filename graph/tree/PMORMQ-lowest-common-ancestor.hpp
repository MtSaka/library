#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"
#include "../../ds/segment/plus-minus-one-rmq.hpp"

template <typename T = UnweightedEdge>
struct PMORMQLCA : Graph<T> {
    using Graph<T>::g;
    vector<int> ord, dep, in;
    PlusMinusOneRMQ<int> rmq;
    PMORMQLCA(int n) : Graph<T>(n) {}
    PMORMQLCA(const Graph<T>& g) : Graph<T>(g) {}
    void build(int root = 0) {
        ord.reserve(g.size() * 2 - 1, -1);
        dep.reserve(g.size() * 2 - 1, -1);
        in.assign(g.size(), -1);
        dfs(root, -1, 0);
        rmq = PlusMinusOneRMQ<int>(dep);
    }
    int lca(int u, int v) const {
        if (in[u] > in[v]) swap(u, v);
        return ord[rmq.prod(in[u], in[v] + 1).second];
    }

   private:
    void dfs(int v, int par, int d) {
        in[v] = ord.size();
        ord.emplace_back(v);
        dep.emplace_back(d);
        for (auto&& e : g[v]) {
            if (e == par) continue;
            dfs(e, v, d + 1);
            ord.emplace_back(v);
            dep.emplace_back(d);
        }
    }
};
/**
 * @brief Lowest Common Ancestor (Plus Minus One RMQ)
 * @ref https://info.atcoder.jp/entry/algorithm_lectures/linear_time_lca
 */