// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_count_distinct
#include "../../../template/template.hpp"
#include "../../../ds/segment/static-range-count-distinct.hpp"
int main() {
    LL(n, q);
    vl a(n);
    sc >> a;
    vector<pair<int, int>> queries(q);
    sc >> queries;
    auto res = static_range_count_distinct(a, queries);
    for (auto x : res) print(x);
}