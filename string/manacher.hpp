#pragma once
#include "../template/template.hpp"

template <typename Cont, typename Cmp>
vector<int> manacher(Cont s, const Cmp& cmp, bool calc_even = true) {
    if (calc_even) {
        int n = (int)s.size();
        s.resize(2 * n - 1);
        for (int i = n - 1; i >= 0; --i) s[2 * i] = s[i];
        for (int i = 0; i < n; ++i) s[2 * i + 1] = s[0];
    }
    int n = (int)s.size();
    vector<int> rad(n);
    {
        int i = 0, j = 0;
        while (i < n) {
            while (i - j >= 0 && i + j < n && cmp(s[i - j], s[i + j])) ++j;
            rad[i] = j;
            int k = 1;
            while (i - k >= 0 && i + k < n && k + rad[i - k] < j) rad[i + k] = rad[i - k], ++k;
            i += k;
            j -= k;
        }
    }
    if (calc_even) {
        for (int i = 0; i < n; ++i)
            if (!((i ^ rad[i]) & 1)) rad[i]--;
    } else {
        for (auto& e : rad) e = 2 * e - 1;
    }
    return rad;
}
template <typename Cont>
vector<int> manacher(const Cont& s, bool calc_even = true) { return manacher(s, equal_to<typename Cont::value_type>(), calc_even); }
/**
 * @brief Manacher Algorithm(最長回文)
 */