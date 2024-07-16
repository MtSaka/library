#pragma once
#include "fps.hpp"

// c[i]= sum_j b[j]*a[i+j]
template <typename T>
FormalPowerSeries<T> middle_product(const FormalPowerSeries<T>& a, const FormalPowerSeries<T>& b) {
    const int n = a.size(), m = b.size();
    if (b.empty()) return FormalPowerSeries<T>(n - m + 1);
    if (min(m, n - m + 1) <= 64) {
        FormalPowerSeries<T> c(n - m + 1);
        rep(i, n - m + 1) rep(j, m) c[i] += a[i + j] * b[j];
        return c;
    }
    const int l = 1 << ceil_log2(2 * n - 1);
    vector<T> fa(l), fb(l);
    copy(a.begin(), a.end(), fa.begin());
    copy(b.rbegin(), b.rend(), fb.begin());
    ntt(fa), ntt(fb);
    rep(i, l) fa[i] *= fb[i];
    intt(fa);
    fa.resize(n);
    fa.erase(fa.begin(), fa.begin() + m - 1);
    return fa;
}
/**
 * @brief Middle Product
 */