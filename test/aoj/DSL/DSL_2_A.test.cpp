// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
#include "../../../ds/segment/segment-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RangeMinimumQuery<int, (1ull << 31) - 1> RMQ(n);
    while (q--) {
        INT(t, x, y);
        if (t == 0)
            RMQ.set(x, y);
        else
            print(RMQ.prod(x, y + 1));
    }
}