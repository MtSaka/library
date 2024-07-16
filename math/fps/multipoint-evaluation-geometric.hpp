#pragma once
#include "fps.hpp"
#include "middle-product.hpp"

template <typename T>
vector<T> multipoint_evaluation_geometric(FormalPowerSeries<T> f, T a, T r, int m) {
    if (m == 0) return {};
    const int n = f.size();
    if (r == T(0)) {
        vector<T> res(m, f[0]);
        res[0] = f(a);
        return res;
    }
    if (n < 64 || m < 64) {
        vector<T> res(m);
        rep(i, m) res[i] = f(a), a *= r;
        return res;
    }
    T pow_a = 1;
    rep(i, n) f[i] *= pow_a, pow_a *= a;
    auto calc = [](T r, int m) -> FormalPowerSeries<T> {
        FormalPowerSeries<T> res(m);
        T pow_r = 1;
        res[0] = 1;
        rep(i, m - 1) res[i + 1] = res[i] * pow_r, pow_r *= r;
        return res;
    };
    auto r_memo = calc(r, n + m - 1), r_inv_memo = calc(r.inv(), max(n, m));
    f.dot(r_inv_memo);
    auto res = middle_product(r_memo, f);
    rep(i, m) res[i] *= r_inv_memo[i];
    return res;
}
/**
 * @brief Multipoint Evaluation (Geometric Sequence)
 * @ref https://noshi91.github.io/algorithm-encyclopedia/chirp-z-transform
 */