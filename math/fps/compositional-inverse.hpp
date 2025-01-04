#pragma once

#include "fps.hpp"
#include "power-projection.hpp"

template <typename mint>
FormalPowerSeries<mint> composittional_inverse(const FormalPowerSeries<mint>& f) {
    using fps = FormalPowerSeries<mint>;
    const int n = f.size() - 1;
    fps h = power_projection(f) * n;
    rep(i, 1, n + 1) h[i] /= i;
    h = h.rev();
    h *= h[0].inv();
    fps g = fps(h.log() * mint(-n).inv()).exp();
    g *= f[1].inv();
    return (g << 1).pre(f.size());
}