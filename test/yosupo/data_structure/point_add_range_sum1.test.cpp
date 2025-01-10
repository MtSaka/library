// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include "../../../ds/segment/segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    vl a(n);
    sc >> a;
    RangeSumQuery<ll> RSQ(a);
    rep(q) {
        int t, l, r;
        sc >> t >> l >> r;
        if (t == 0)
            RSQ.apply(l, r);
        else
            print(RSQ.prod(l, r));
    }
}