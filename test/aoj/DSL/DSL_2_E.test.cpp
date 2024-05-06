// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
#include "../../../ds/segment/dual-segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeAddQuery<int> RAQ(n);
    while (q--) {
        INT(t);
        if (t == 0) {
            INT(l, r, x);
            RAQ.apply(l - 1, r, x);
        } else {
            INT(k);
            print(RAQ[k - 1]);
        }
    }
}