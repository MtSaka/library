#pragma once
#include "../../template/template.hpp"
ull MaximumIndependentSet(const vector<vi>& g) {
    const int n = g.size();
    vector<ull> adj(n);
    rep(i, n) for (auto& e : g[i]) adj[i] |= 1ull << e;
    int ans = 0;
    ull res = 0;
    auto dfs = REC([&](auto&& dfs, ull now, ull rest) -> void {
        pair<int, int> p = {-1, -1};
        while (true) {
            bool f = false;
            rep(v, n) if ((rest >> v) & 1) {
                int deg = popcnt(adj[v] & rest);
                chmax(p, pair<int, int>{deg, v});
                if (deg <= 1) {
                    rest ^= 1ull << v, rest &= ~adj[v], now |= 1ull << v;
                    f = true;
                }
            }
            if (!f) break;
            p = {-1, -1};
        }
        const int sz1 = popcnt(now), sz2 = popcnt(rest);
        if (chmax(ans, sz1)) res = now;
        if (sz2 == 0 || sz1 + sz2 <= ans) return;
        const int v = p.second;
        rest &= ~(1ull << v);
        dfs(now, rest);
        now |= 1ull << v;
        dfs(now, rest & (~adj[v]));
    });
    dfs(0, (1ull << n) - 1);
    return res;
}
/**
 * @brief Maximum Independent Set
 */