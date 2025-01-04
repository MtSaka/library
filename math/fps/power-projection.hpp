#pragma once

#include "fps.hpp"
#include "multiply2d.hpp"

template <typename mint>
FormalPowerSeries<mint> power_projection(FormalPowerSeries<mint> f, FormalPowerSeries<mint> g = {1}) {
    using fps = FormalPowerSeries<mint>;
    vector<fps> p(f.size(), fps(2)), q(f.size(), fps(2));
    q[0][0] = 1;
    rep(i, f.size()) q[i][1] = -f[i];
    rep(i, g.size()) p[i][0] = g[i];
    int n = f.size() - 1, k = 1;
    while (n) {
        auto r = q;
        for (int i = 1; i <= n; i += 2)
            r[i] = -r[i];
        auto s = multiply2d(p, r);
        auto t = multiply2d(q, r);
        vector<fps> u(n / 2 + 1, fps(2 * k + 1)), v(n / 2 + 1, fps(2 * k + 1));
        rep(i, n / 2 + 1) u[i] = s[i * 2 + n % 2], v[i] = t[i * 2];
        p = u, q = v;
        n /= 2, k *= 2;
    }
    return (p[0] * q[0].inv()).pre(f.size());
}