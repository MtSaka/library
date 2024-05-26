#pragma once
#include "../../dp/smawk.hpp"
#include "../../template/template.hpp"

template <typename T>
vector<T> min_plus_convolution(const vector<T>& a, const vector<T>& b) {
    const int n = a.size(), m = b.size();
    auto idx = smawk_comp(n + m - 1, n, [&](int i, int j, int k) {
        if (i - k < 0) return false;
        if (i - j >= m) return true;
        return a[j] + b[i - j] > a[k] + b[i - k];
    });
    vector<T> res(n + m - 1);
    for (int i = 0; i < n + m - 1; ++i) {
        res[i] = a[idx[i]] + b[i - idx[i]];
    }
    return res;
}

/**
 * @brief Min-Plus Convolution (Convex and Arbitrary)
 */