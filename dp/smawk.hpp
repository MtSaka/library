#pragma once
#include "../template/template.hpp"

template <typename Comp>
vector<int> smawk_comp(int row_sz, int col_sz, const Comp& cmp) {
    auto rec = REC([&](auto&& rec, const vector<int>& row, const vector<int>& col) -> vector<int> {
        const int n = row.size();
        if (n == 0) return {};
        vector<int> col2;
        for (const auto& i : col) {
            while (!col2.empty() && cmp(row[col2.size() - 1], col2.back(), i)) col2.pop_back();
            if ((int)col2.size() < n) col2.emplace_back(i);
        }
        vector<int> row2;
        for (int i = 1; i < n; i += 2) row2.emplace_back(row[i]);
        const auto ret_tmp = rec(row2, col2);
        vector<int> ans(n);
        for (int i = 0; i < (int)ret_tmp.size(); i++) ans[2 * i + 1] = ret_tmp[i];
        int j = 0;
        for (int i = 0; i < n; i += 2) {
            ans[i] = col2[j];
            const int r = (i + 1 == n ? col2.back() : ans[i + 1]);
            while (col2[j] != r) {
                j++;
                if (cmp(row[i], ans[i], col2[j])) ans[i] = col2[j];
            }
        }
        return ans;
    });
    vector<int> row(row_sz);
    vector<int> col(col_sz);
    iota(all(row), 0);
    iota(all(col), 0);
    return rec(row, col);
}
template <typename F>
vector<int> smawk(int row_sz, int col_sz, const F& f) {
    auto cmp = [&](int i, int j, int k) {
        if (i <= k) return false;
        if (i <= j) return true;
        return f(j, i) > f(k, i);
    };
    return smawk_comp(row_sz, col_sz, cmp);
}
/**
 * @brief Smawk's Algorithm
 */