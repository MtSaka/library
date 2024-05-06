#pragma once
#include "../template/template.hpp"

template <typename Cont, typename Cmp>
vector<int> ZAlgorithm(const Cont& s, const Cmp& cmp) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && cmp(s[j], s[i + j])) ++j;
        z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < n && k + z[k] < j) z[i + k] = z[k], ++k;
        i += k;
        j -= k;
    }
    return z;
}
template <typename Cont>
vector<int> ZAlgorithm(const Cont& s) { return ZAlgorithm(s, equal_to<typename Cont::value_type>()); }
/**
 * @brief Z Algorithm
 */