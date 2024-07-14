#pragma once

#include "convolution.hpp"
template <typename T, enable_if_t<is_modint<T>::value>* = nullptr>
vector<T> convolution_large(const vector<T>& a, const vector<T>& b) {
    const int n = a.size(), m = b.size();
    constexpr unsigned int p = T::get_mod();
    if (n + m - 1 <= ((p - 1) & (1 - p))) return convolution(a, b);
    constexpr int lg = ceil_log2((p - 1) & (1 - p)) - 1;
    vector c(4, vector<T>(1 << (lg + 1)));
    vector d(4, vector<T>(1 << (lg + 1)));
    constexpr int mask = (1 << lg) - 1;
    rep(i, n) c[i >> lg][i & mask] = a[i];
    rep(i, m) d[i >> lg][i & mask] = b[i];
    rep(i, 4) ntt(c[i]);
    rep(i, 4) ntt(d[i]);
    vector<T> ans(1 << (lg + 3));
    rep(i, 7) {
        vector<T> e(1 << (lg + 1));
        rep(j, 4) {
            const int k = i - j;
            if (k < 0 || k >= 4) continue;
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