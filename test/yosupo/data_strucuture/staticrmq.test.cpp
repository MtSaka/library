// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "../../../ds/segment/sparse-table.hpp"
#include "../../../others/monoid.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    vi a(n);
    sc >> a;
    SparseTable<Monoid::Min<int>> st(a);
    rep(q) {
        INT(l, r);
        print(st.prod(l, r));
    }
}