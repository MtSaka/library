#pragma once

#include "convolution.hpp"
template <typename T, enable_if_t<is_modint<T>::value>* = nullptr>
vector<T> convolution_large(const vector<T>& a, const vector<T>& b) {
    const size_t n = a.size(), m = b.size();
    constexpr unsigned int p = T::get_mod();
    if (n + m <= 1 + ((p - 1) & (1 - p))) return convolution(a, b);
    constexpr int lg = ceil_log2((p - 1) & (1 - p)) - 1;
    constexpr int mask = (1 << lg) - 1;
    const int d1 = (n + mask) >> lg, d2 = (m + mask) >> lg;
    vector c(d1, vector<T>(1 << (lg + 1)));
    vector d(d2, vector<T>(1 << (lg + 1)));
    rep(i, n) c[i >> lg][i & mask] = a[i];
    rep(i, m) d[i >> lg][i & mask] = b[i];
    rep(i, d1) ntt(c[i]);
    rep(i, d2) ntt(d[i]);
    vector<T> ans((d1 + d2) << lg);
    rep(i, d1 + d2 - 1) {
        vector<T> e(1 << (lg + 1));
        rep(j, d1) {
            const int k = i - j;
            if (k < 0 || k >= d2) continue;
            rep(l, 1 << (lg + 1)) e[l] += c[j][l] * d[k][l];
        }
        intt(e);
        rep(j, 1 << (lg + 1)) ans[(i << lg) + j] += e[j];
    }
    ans.resize(n + m - 1);
    return ans;
}
/**
 * @brief Large Convolution
 */