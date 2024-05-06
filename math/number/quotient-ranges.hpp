#pragma once
#include "../../template/template.hpp"

template <typename T>
vector<pair<T, pair<T, T>>> quotient_ranges(T n) {
    vector<pair<T, pair<T, T>>> ans;
    T m;
    for (m = 1; m * m <= n; m++) {
        ans.emplace_back(n / m, make_pair(m, m));
    }
    for (T i = m; i >= 1; i--) {
        if (n / (i + 1) + 1 <= n / i && ans.back().second.second < n / i) ans.emplace_back(i, make_pair(n / (i + 1) + 1, n / i));
    }
    return ans;
}
/**
 * @brief Quotient Ranges(商列挙)
 */