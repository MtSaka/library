// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H
#include "../../../ds/segment/lazy-segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeAddQueryRangeMinimumQuery<int> RAQRMQ(n, 0);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            RAQRMQ.apply(l, r + 1, x);
        } else {
            INT(l, r);
            print(RAQRMQ.prod(l, r + 1));
        }
    }
}