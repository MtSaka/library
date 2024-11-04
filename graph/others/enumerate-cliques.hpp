#pragma once
#include "../../template/template.hpp"
template <typename F>
void EnumerateCliques(const vector<vector<int>>& g, const F& f) {
    const int n = g.size();
    vector<vector<int>> can(n, vector<int>(n, 0));
    vector<int> done(n, 0);
    vector<int> deg(n);
    rep(i, n) {
        deg[i] = g[i].size();
        for (auto e : g[i]) {
            can[i][e] = can[e][i] = 1;
        }
    }
    vector<int> c;
    rep(n) {
        int v = -1;
        int min_deg = n;
        rep(i, n) if (!done[i] && chmin(min_deg, deg[i])) v = i;
        vector<int> adj;
        for (auto& e : g[v])
            if (!done[e]) adj.eb(e);
        c.eb(v);
        auto dfs = REC([&](auto&& dfs, int k) -> void {
            f(c);
            for (int i = k; i < (int)adj.size(); ++i) {
                bool flag = true;
                for (auto& e : c)
                    if (!can[adj[i]][e]) {
                        flag = false;
                        break;
                    }
                if (flag) {
                    c.emplace_back(adj[i]);
                    dfs(i + 1);
                    c.pop_back();
                }
            }
        });
        dfs(0);
        c.clear();
        done[v] = 1;
        for (auto& e : g[v]) deg[e]--;
    }
}

/**
 * @brief Enumerate Cliques
 */