#pragma once
#include "../../template/template.hpp"

template <typename T>
vector<pair<T, pair<T, T>>> quotient_ranges(T n) {
    vector<pair<T, pair<T, T>>> ans;
    T sq = sqrtl(n);
    if (sq * sq + sq <= n) sq++;
    const T m = n / sq;
    ans.reserve(m + sq - 1);
    rep(i, 1, sq) ans.emplace_back(n / i, make_pair(i, i));
    rrep(i, 1, m + 1) {
        const T l = n / (i + 1) + 1, r = n / i;
        ans.emplace_back(i, make_pair(l, r));
    }
    return ans;
}
/**
 * @brief Quotient Ranges(商列挙)
 */