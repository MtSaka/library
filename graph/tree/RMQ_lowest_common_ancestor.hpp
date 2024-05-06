#pragma once
#include "../../ds/segment/sparse-table.hpp"
#include "../graph-template.hpp"

namespace Monoid {
struct PairMinForLCA {
    using value_type = pair<int, int>;
    static value_type op(const value_type& a, const value_type& b) {
        return a.first < b.first ? a : b;
    }
    static value_type id() { return {infinity<int>::value, -1}; }
};
}  // namespace Monoid
template <typename T = UnweightedEdge>
struct RMQ_LCA : Graph<T> {
    using Graph<T>::g;
    vector<int> in;
    RMQ_LCA(int n) : Graph<T>(n) {}
    RMQ_LCA(const Graph<T>& g) : Graph<T>(g) {}
    void build(int root = 0) {
        in.resize(g.size());
        dfs(root, -1, 0);
        RMQ.init(rmqvec);
    }
    int lca(int u, int v) const {
        if (in[u] > in[v]) swap(u, v);
        return u == v ? u : RMQ.prod(in[u], in[v]).second;
    }

   private:
    vector<pair<int, int>> rmqvec;
    SparseTable<Monoid::PairMinForLCA> RMQ;
    void dfs(int idx, int par, int d) {
        in[idx] = (int)rmqvec.size();
        rmqvec.emplace_back(d, idx);
        for (auto& e : g[idx])
            if (e != par) {
                dfs(e, idx, d + 1);
                rmqvec.emplace_back(d, idx);
            }
    }
};
/**
 * @brief RMQ Lowest Common Ancestor(最小共通祖先)
 */