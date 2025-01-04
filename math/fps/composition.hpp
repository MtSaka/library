#pragma once

#include "fps.hpp"
#include "multiply2d.hpp"

template <typename mint>
FormalPowerSeries<mint> composite(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g) {
    using fps = FormalPowerSeries<mint>;
    vector<fps> Q(f.size(), fps(2));
    Q[0][0] = 1;
    rep(i, f.size()) Q[i][1] = -f[i];
    auto dfs = REC([&](auto&& dfs, const vector<fps>& q, int n, int k) -> vector<fps> {
        if (n == 0) {
            fps h = g * q[0].inv().rev();
            vector<fps> p(n + 1, fps(k + 1));
            rep(i, g.size()) p[0][i] = h[i + q[0].size() - 1];
            return p;
        }
        auto r = q;
        for (int i = 1; i <= n; i += 2)
            r[i] = -r[i];
        auto t = multiply2d(q, r);
        rep(i, n / 2 + 1) t[i] = t[i * 2];
        t.resize(n / 2 + 1);
        auto u = dfs(t, n / 2, k * 2);
        vector<fps> s(n + 1, fps(k * 2 + 1));
        for (int i = 0; i <= n / 2; i++)
            s[i * 2 + n % 2] = u[i];
        vector<fps> revr = r;
        reverse(revr.begin(), revr.end());
        for (auto& e : revr)
            e = e.rev();
        vector<fps> p = multiply2d(s, revr);
        p.resize(2 * n + 1);
        p.erase(p.begin(), p.begin() + n);
        rep(i, n + 1) p[i].erase(p[i].begin(), p[i].begin() + k), p[i].resize(k + 1);
        return p;
    });
    auto P = dfs(Q, f.size() - 1, 1);
    fps res(f.size());
    rep(i, f.size()) res[i] = P[i][0];
    return res.rev();
}