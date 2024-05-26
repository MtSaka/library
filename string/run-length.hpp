#pragma once
#include "../template/template.hpp"

template <typename Cont, typename Comp>
vector<pair<typename Cont::value_type, int>> run_length(const Cont& c, const Comp& cmp) {
    vector<pair<typename Cont::value_type, int>> ret;
    if (c.empty()) return ret;
    ret.emplace_back(c.front(), 1);
    for (int i = 1; i < (int)c.size(); i++) {
        if (cmp(c[i], ret.back().first)) {
            ret.back().second++;
        } else {
            ret.emplace_back(c[i], 1);
        }
    }
    return ret;
}
template <typename Cont>
vector<pair<typename Cont::value_type, int>> run_length(const Cont& c) { return run_length(c, equal_to<typename Cont::value_type>()); }