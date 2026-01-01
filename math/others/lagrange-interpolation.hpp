#pragma once
#include "../../template/template.hpp"
#include "combinatorics.hpp"

template <typename T, typename Comb = Combinatorics<T>>
T lagrange_interpolation(const vector<T>& y, const long long& t) {
    const int n = y.size() - 1;
    Comb::extend(n);
    if (t <= n) return y[t];
    T ret = 0;
    vector<T> dp(n + 1, 1), pd(n + 1, 1);
    for (int i = 0; i < n; i++) dp[i + 1] = dp[i] * T(t - i);
    for (int i = n; i > 0; i--) pd[i - 1] = pd[i] * T(t - i);
    for (int i = 0; i <= n; i++) {
        T tmp = y[i] * dp[i] * pd[i] * Comb::finv(i) * Comb::finv(n - i);
        if ((n - i) & 1)
            ret -= tmp;
        else
            ret += tmp;
    }
    return ret;
}
/**
 * @brief Lagrange Interpolation(ラグランジュ補間)
 */