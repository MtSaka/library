#pragma once
#include "../../template/template.hpp"

vector<ll> prime_factor(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) res.push_back(n);
    return res;
}
/**
 * @brief Prime Factorization(素因数分解)
 */