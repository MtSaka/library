// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_set_range_composite
#include "library/template/template.hpp"
#include "library/ds/segment/range-assign-segmnet-tree.hpp"
#include "library/others/monoid2.hpp"
#include "library/math/modular/modint.hpp"
using mint = ModInt<998244353>;
int main() {
    LL(n, q);
    vector<pair<mint, mint>> v(n);
    sc >> v;
    RangeAssignSegmnetTree<Monoid::Composite<mint>> seg(v);
    rep(q) {
        LL(t);
        if (t == 0) {
            LL(l, r, c, d);
            seg.set(l, r, pair<mint, mint>{c, d});
        } else {
            LL(l, r, x);
            auto [a, b] = seg.prod(l, r);
            print(a * x + b);
        }
    }
}