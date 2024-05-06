#pragma once
#include "../../template/template.hpp"

template <typename S, typename T = S>
struct ReRooting {
    struct Edge {
        int from, to;
        S cost;
        T dp, ndp;
    };
    using F = function<T(T, T)>;
    using G = function<T(T, Edge)>;
    vector<vector<Edge>> graph;
    const F f;
    const G g;
    const T id;
    vector<T> subdp, dp;
    void add_edge(int u, int v, const S& d) {
        graph[u].emplace_back(Edge{u, v, d, id, id});
        graph[v].emplace_back(Edge{v, u, d, id, id});
    }
    void add_directed_edge(int u, int v, const S& d) {
        graph[u].emplace_back(Edge{u, v, d, id, id});
    }
    ReRooting(int n, const F& f, const G& g, const T& id = T{}) : graph(n), f(f), g(g), id(id), subdp(n, id), dp(n, id) {}
    void dfs_sub(int x, int p) {
        for (auto& e : graph[x])
            if (e.to != p) {
                dfs_sub(e.to, x);
                e.dp = g(subdp[e.to], e);
                subdp[x] = f(subdp[x], e.dp);
            }
    }
    void dfs_all(int x, int p, T top) {
        T now = id;
        for (auto& e : graph[x]) {
            e.ndp = now;
            if (e.to == p) e.dp = g(top, e);
            now = f(now, e.dp);
        }
        dp[x] = now;
        now = id;
        for (int i = (int)graph[x].size() - 1; i >= 0; i--) {
            auto& e = graph[x][i];
            if (e.to != p) dfs_all(e.to, x, f(e.ndp, now));
            now = f(e.dp, now);
        }
    }
    vector<T> solve() {
        dfs_sub(0, -1);
        dfs_all(0, -1, id);
        return dp;
    }
};
/**
 * @brief ReRooting(全方位木DP)
 */