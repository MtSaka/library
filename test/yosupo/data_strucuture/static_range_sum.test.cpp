// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_sum
#include "../../../ds/segment/disjoint-sparse-table.hpp"
#include "../../../others/monoid.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    vl a(n);
    sc >> a;
    DisjointSparseTable<Monoid::Sum<ll>> st(a);
    while (q--) {
        INT(l, r);
        print(st.prod(l, r));
    }
}