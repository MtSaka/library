// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
#include "../../../ds/segment/lazy-segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeUpdateQueryRangeSumQuery<int> RUQRSQ(n);
    while (q--) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            RUQRSQ.apply(l, r + 1, x);
        } else {
            INT(l, r);
            print(RUQRSQ.prod(l, r + 1));
        }
    }
}