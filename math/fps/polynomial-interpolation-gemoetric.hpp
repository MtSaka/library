#pragma once
#include "fps.hpp"
#include "multipoint-evaluation-geometric.hpp"

template <typename T>
FormalPowerSeries<T> polynomial_interpolation_gemoetric(vector<T> y, const T& a, const T& r) {
    const int n = y.size();
    if (n == 0) return {};
    if (n == 1) return {y[0]};
    if (r == 0) {
        return {y[1], (y[0] - y[1]) / a};
    }
    vector<T> pow_r(n + 1), pow_invr(n + 1), inv_s(n);
    T s = 1;
    const T inv_r = T(1) / r;
    {
        pow_r[0] = pow_invr[0] = inv_s[0] = 1;
        rep(i, n) {
            if (i) s *= (1 - pow_r[i]);
            pow_r[i + 1] = pow_r[i] * r;
            pow_invr[i + 1] = pow_invr[i] * inv_r;
        }
        inv_s[n - 1] = T(1) / s;
        s *= (1 - pow_r[n]);
        rrep(i, n - 1) inv_s[i] = inv_s[i + 1] * (1 - pow_r[i + 1]);
    }
    T v = 1;
    rep(i, n) {
        y[i] *= v * inv_s[i] * inv_s[n - i - 1];
        if (i & 1) y[i] = -y[i];
        if (i != n - 1) v *= pow_invr[n - 2 - i];
    }
    FormalPowerSeries<T> f1(n + 1);
    v = 1;
    rep(i, n + 1) {
        if (i == 0 || i == n)
            f1[i] = v;
        else
            f1[i] = v * s * inv_s[i] * inv_s[n - i];
        if (i & 1) f1[i] = -f1[i];
        v *= pow_r[i];
    }
    FormalPowerSeries<T> f2 = multipoint_evaluation_geometric(FormalPowerSeries<T>(y), T(1), r, n);
    auto res = (f1 * f2);
    res.resize(n);
    reverse(res.begin(), res.end());
    const T inva = T(1) / a;
    v = 1;
    rep(i, n) res[i] *= v, v *= inva;
    return res;
}
/**
 * @brief Polynomial Interpolation (Geometric Sequence)
 * @ref https://noshi91.github.io/algorithm-encyclopedia/polynomial-interpolation-geometric
 */