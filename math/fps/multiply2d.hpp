#pragma once

#include "fps.hpp"

template <typename mint>
vector<FormalPowerSeries<mint>> transpose(const vector<FormalPowerSeries<mint>>& f) {
    const int h = f.size(), w = f[0].size();
    vector<FormalPowerSeries<mint>> res(w, FormalPowerSeries<mint>(h));
    rep(i, h) rep(j, w) res[j][i] = f[i][j];
    return res;
}
template <typename mint>
vector<FormalPowerSeries<mint>> multiply2d(const vector<FormalPowerSeries<mint>>& f, const vector<FormalPowerSeries<mint>>& g) {
    const int h = f.size() + g.size() - 1;
    const int w = f[0].size() + g[0].size() - 1;
    if (h < w) {
        auto ft = transpose(f);
        auto gt = transpose(g);
        return transpose(multiply2d(ft, gt));
    }
    FormalPowerSeries<mint> a(f.size() * w), b(g.size() * w);
    rep(i, f.size()) rep(j, f[0].size()) a[i * w + j] = f[i][j];
    rep(i, g.size()) rep(j, g[0].size()) b[i * w + j] = g[i][j];
    a *= b;
    vector<FormalPowerSeries<mint>> res(h, FormalPowerSeries<mint>(w));
    rep(i, h) rep(j, w) {
        res[i][j] = a[i * w + j];
    }
    return res;
}