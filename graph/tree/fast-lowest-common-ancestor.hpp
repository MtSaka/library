#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T = UnweightedEdge>
struct LCA : Graph<T> {
    using Graph<T>::g;
    vector<int> dep;
    vector<T> sum;
    vector<int> par;
    vector<int> leap;
    LCA(int n) : Graph<T>(n) {}
    LCA(const Graph<T>& g) : Graph<T>(g) {}
    void build(int root = 0) {
        dep.assign(g.size(), 0);
        sum.assign(g.size(), T());
        par.assign(g.size(), -1);
        leap.assign(g.size(), root);
        dfs(root, root, 0);
    }
    int la(int v, int k) const {
        while (k > 0) {
            if (dep[v] - k <= dep[leap[v]]) {
                k -= dep[v] - dep[leap[v]];
                v = leap[v];
            } else {
                k--;
                v = par[v];
            }
        }
        return v;
    }
    int lca(int u, int v) const {
        if (dep[u] > dep[v]) swap(u, v);
        v = la(v, dep[v] - dep[u]);
        if (u == v) return u;
        while (u != v) {
            if (leap[u] == leap[v]) {
                u = par[u];
                v = par[v];
            } else {
                u = leap[u];
                v = leap[v];
            }
        }
        return u;
    }
    int dist(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
    T weight(int u, int v) const { return sum[u] + sum[v] - 2 * sum[lca(u, v)]; }
    int jump(int from, int to, int k) const {
        int l = lca(from, to);
        int d1 = dep[from] - dep[l];
        int d2 = dep[to] - dep[l];
        if (d1 + d2 < k) return -1;
        if (d1 >= k) return la(from, k);
        return la(to, d1 + d2 - k);
    }

   private:
    void dfs(int idx, int p, int d) {
        dep[idx] = d;
        const int p2 = leap[p];
        leap[idx] = (dep[p] - dep[p2] == dep[p2] - dep[leap[p2]] ? leap[p2] : p);
        par[idx] = p;
        for (auto to : g[idx]) {
            if (to == p) continue;
            sum[to] = sum[idx] + to.cost;
            dfs(to, idx, d + 1);
        }
    }
};
/**
 * @brief Lowest Common Ancestor(最小共通祖先)
 */