// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "../../../ds/segment/disjoint-sparse-table.hpp"
#include "../../../others/monoid.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    vi a(n);
    cin >> a;
    DisjointSparseTable<Monoid::Min<int>> st(a);
    while (q--) {
        INT(l, r);
        print(st.prod(l, r));
    }
}