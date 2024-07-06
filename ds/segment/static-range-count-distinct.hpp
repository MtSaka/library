#pragma once

#include "../../template/template.hpp"
#include "binary-indexed-tree.hpp"

template <typename T>
vector<int> static_range_count_distinct(vector<T> v, const vector<pair<int, int>>& queries) {
    const int n = v.size();
    compressor<T> press(v);
    press.build();
    press.press(v);
    const int m = press.size();
    vector<int> last(m, -1);
    BinaryIndexedTree<int> bit(n);
    vector<int> res(queries.size());
    vector<vector<pair<int, int>>> query(n);
    for (int i = 0; i < (int)queries.size(); i++) {
        const auto [l, r] = queries[i];
        if (l != r) query[r - 1].emplace_back(l, i);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (last[v[i]] != -1)
            bit.add(last[v[i]], -1);
        else
            cnt++;
        bit.add(i, 1);
        last[v[i]] = i;
        for (const auto [l, idx] : query[i]) res[idx] = cnt - bit.sum(l);
    }
    return res;
}
/**
 * @brief Static Range Count Distinct
 */