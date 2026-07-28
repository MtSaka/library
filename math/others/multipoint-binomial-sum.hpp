#pragma once
#include "combinatorics.hpp"
#include "../../others/mo.hpp"

template <typename T>
vector<T> prefix_sum_binomial(const vector<pair<int, int>>& qs) {
    int N = 2;
    for (auto [n, k] : qs) chmax(N, n);
    Mo mo(N);
    for (auto [n, k] : qs) mo.add(k, n);
    vector<T> ans(qs.size());
    T inv2 = T(1) / T(2);
    int n = 0, m = 0;
    T now = 1;
    Combinatorics<T> comb;
    auto al = [&](int) { now -= comb.com(n, m--); };
    auto ar = [&](int) { now += now - comb.com(n++, m); };
    auto dl = [&](int) { now += comb.com(n, ++m); };
    auto dr = [&](int) { now = (now + comb.com(--n, m)) * inv2; };
    auto rem = [&](int i) { ans[i] = now; };
    mo.run(al, ar, dl, dr, rem);
    return ans;
}

/**
 * @brief: Offline Prefix Sum of Binomial
 */