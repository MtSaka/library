// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
#include "../../../ds/segment/dual-segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeUpdateQuery<int> RUQ(n, (1u << 31) - 1);
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            RUQ.apply(l, r + 1, x);
        } else {
            INT(k);
            print(RUQ[k]);
        }
    }
}