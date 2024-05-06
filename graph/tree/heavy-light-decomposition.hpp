#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T>
struct HeavyLightDecomposition {
   private:
    int n, time, r;
    vector<int> sz, head, in, out, par, rev;
    const Graph<T>& g;
    int dfs_sz(int v, int p) {
        sz[v] = 1;
        for (auto& e : g[v])
            if (e.to != p) sz[v] += dfs_sz(e.to, v);
        return sz[v];
    }
    void dfs_hld(int v, int p) {
        par[v] = p;
        in[v] = time++;
        rev[in[v]] = v;
        int idx = -1;
        for (auto& e : g[v])
            if (e.to != p && (idx == -1 || sz[idx] < sz[e.to])) idx = e.to;
        if (idx != -1) {
            head[idx] = head[v];
            dfs_hld(idx, v);
        }
        for (auto& e : g[v])
            if (e.to != p && e.to != idx) {
                head[e.to] = e.to;
                dfs_hld(e.to, v);
            }
        out[v] = time;
    }

   public:
    HeavyLightDecomposition(const Graph<T>& g, int r = 0) : n(g.size()), time(0), r(r), g(g), sz(n, -1), head(n, r), in(n, -1), out(n, -1), par(n, r), rev(n, -1) {
        dfs_sz(r, -1);
        head[r] = r;
        dfs_hld(r, -1);
    }
    pair<int, int> get_id(int v) const { return {in[v], out[v]}; }
    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (in[head[u]] > in[head[v]]) swap(u, v);
            v = par[head[v]];
        }
        return in[u] < in[v] ? u : v;
    }
    int la(int v, int k) const {
        while (k) {
            int u = head[v];
            if (in[v] - in[u] >= k) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
        return v;
    }
    // [u,v)
    vector<pair<int, int>> up_path(int u, int v) const {
        vector<pair<int, int>> res;
        while (head[u] != head[v]) {
            res.emplace_back(in[u], in[head[u]]);
            u = par[head[u]];
        }
        if (u != v) res.emplace_back(in[u], in[v] + 1);
        return res;
    }
    // (u,v]
    vector<pair<int, int>> down_path(int u, int v) const {
        auto res = up_path(v, u);
        for (auto& e : res) swap(e.first, e.second);
        reverse(res.begin(), res.end());
        return res;
    }
    template <typename F>
    void path_query(int u, int v, const F& f, bool edge = false) {
        path_query(u, v, f, f, edge);
    }
    template <typename F, typename G>
    void path_query(int u, int v, const F& f, const G& g, bool edge = false) {
        int l = lca(u, v);
        for (auto [a, b] : up_path(u, l)) a > b ? g(b, a + 1) : f(a, b + 1);
        if (!edge) f(in[l], in[l] + 1);
        for (auto [a, b] : down_path(l, v)) a > b ? g(b, a + 1) : f(a, b + 1);
    }
    template <typename F>
    void subtree_query(int v, const F& f, bool edge = false) {
        f(in[v] + edge, out[v]);
    }
};
/**
 * @brief Heavy-Light Decomposition(HL分解)
 */