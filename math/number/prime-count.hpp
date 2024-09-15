#pragma once
#include "../../template/template.hpp"
ll prime_count(const ll n) {
    if (n == 1) return 0;
    const ll sq = sqrtl(n);
    vector<int> small(sq + 1, 0);
    vector<ll> large(sq + 1);
    rep(i, 2, sq + 1) small[i] = (i + 1) / 2;
    rep(i, 1, sq + 1) large[i] = ((double)n / i + 1) / 2;
    int cnt = 1;
    for (ll p = 3; p <= sq; p += 2) {
        if (small[p] == small[p - 1]) continue;
        const ll w = sq / p, q = p * p;
        rep(i, 1, w + 1) large[i] -= large[i * p] - cnt;
        const ll t = min(sq, n / q), m = n / p;
        rep(i, w + 1, t + 1) large[i] -= small[(double)m / i] - cnt;
        rrep(i, q, sq + 1) small[i] -= small[(double)i / p] - cnt;
        cnt++;
    }
    return large[1];
}
/**
 * @brief Prime Count
 */