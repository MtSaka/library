#pragma once
#include "../others/fibonacci-search.hpp"
#include "../template/template.hpp"
#include "alien-dp.hpp"
#include "smawk.hpp"

template <typename F>
bool is_monge(int n, F&& f) {
    rep(i, n) rep(j, i + 1, n) rep(k, j + 1, n) rep(l, k + 1, n) {
        auto lhs = f(i, l) + f(j, k);
        auto rhs = f(i, k) + f(j, l);
        if (lhs < rhs) {
            debug(i, j, k, l, f(i, k), f(i, l), f(j, k), f(j, l));
            return false;
        }
    }
    return true;
}

template <typename F>
vector<function_return_type<F>> monge_dp_update(int n, vector<function_return_type<F>> dp, F&& f) {
    auto g = [&](int i, int j) { return dp[j] + f(j, i); };
    vector<int> idx = smawk(n + 1, n + 1, g);
    vector<function_return_type<F>> res(n + 1, infinity<function_return_type<F>>::max);
    for (int j = 0; j < n + 1; ++j) {
        res[j] = min(res[j], f(idx[j], j));
    }
    return res;
}

template <typename F>
vector<function_return_type<F>> monge_shortest_path(int n, F&& f) {
    vector<function_return_type<F>> dp(n + 1, infinity<function_return_type<F>>::max);
    dp[0] = 0;
    vector<int> min_index(n + 1, 0);
    auto check = [&](int i, int j) {
        if (i <= j) return;
        auto v = dp[j] + f(j, i);
        if (v < dp[i]) {
            dp[i] = v;
            min_index[i] = j;
        }
    };
    check(n, 0);
    REC([&](auto&& rec, int l, int r) -> void {
        if (r - l == 1) return;
        const int m = (l + r) / 2;
        for (int k = min_index[l]; k <= min_index[r]; ++k) check(m, k);
        rec(l, m);
        for (int k = l + 1; k <= m; ++k) check(r, k);
        rec(m, r);
    })
    (0, n);
    return dp;
}

// 0からNまでのd-edge shortest pathを求める
template <typename F>
function_return_type<F> monge_sortest_d_edge_path(int n, int d, function_return_type<F> lim, F&& f) {
    using T = function_return_type<F>;
    return alien_dp_convex(-3 * lim, 3 * lim, d, [&](T lambda) -> T {
        auto cost = [&](int i, int j) -> T { return lambda + f(i, j); };
        auto dp = monge_shortest_path(n, cost);
        return dp[n];
    });
}
/**
 * @brief Monge DP
 */