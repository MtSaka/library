#pragma once
#include "../template/template.hpp"

template <typename F>
vector<function_return_type<F>> larsch_easy(int n, const F&& f) {
    vector<function_return_type<F>> res(n, infinity<function_return_type<F>>::max());
    vector<int> min_index(n, 0);
    auto check = [&](int i, int j) {
        auto v = f(i, j);
        if (v < res[i]) {
            res[i] = v;
            min_index[i] = j;
        }
    };
    check(n - 1, 0);
    auto rec = REC([&](auto&& rec, int l, int r) -> void {
        if (r - l == 1) return;
        const int m = (l + r) / 2;
        for (int k = min_index[l]; k <= min_index[r]; ++k) check(m, k);
        rec(l, m);
        for (int k = l + 1; k <= m; ++k) check(r, k);
        rec(m, r);
    })(0, n - 1);
    return res;
}