#pragma once
#include "../../template/template.hpp"
#include "combinatorics.hpp"

template <typename T>
T lagrange_interpolation(const vector<T>& y, const long long& t) {
    const int n = y.size() - 1;
    Combinatorics<T> c(n);
    if (t <= n) return y[t];
    T ret;
    vector<T> dp(n + 1, 1), pd(n + 1, 1);
    for (int i = 0; i < n; i++) dp[i + 1] = dp[i] * T(t - i);
    for (int i = n; i > 0; i--) pd[i - 1] = pd[i] * T(t - i);
    for (int i = 0; i <= n; i++) {
        T tmp = y[i] * dp[i] * pd[i] * c.finv(i) * c.finv(n - i);
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