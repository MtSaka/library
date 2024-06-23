// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum
#include "../../../ds/segment/lazy-segment-tree.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../others/monoid2.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
using T = pair<mint, mint>;
int main() {
    INT(n, q);
    vector<mint> a(n);
    sc >> a;
    LazySegmentTree<Monoid::AffineSum<mint>> seg(a);
    while (q--) {
        INT(t);
        if (t == 0) {
            INT(l, r, b, c);
            seg.apply(l, r, T{b, c});
        } else {
            INT(l, r);
            print(seg.prod(l, r));
        }
    }
}