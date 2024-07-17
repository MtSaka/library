// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
#include "../../../ds/segment/lazy-segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeAddQueryRangeSumQuery<ll> RAQRSQ(n);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            RAQRSQ.apply(l - 1, r, x);
        } else {
            INT(l, r);
            print(RAQRSQ.prod(l - 1, r));
        }
    }
}