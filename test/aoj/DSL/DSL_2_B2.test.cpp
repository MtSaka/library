// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
#include "../../../ds/segment/segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeSumQuery<int> RSQ(n);
    rep(q) {
        INT(t, a, b);
        if (t == 0)
            RSQ.apply(a - 1, b);
        else
            print(RSQ.prod(a - 1, b));
    }
}