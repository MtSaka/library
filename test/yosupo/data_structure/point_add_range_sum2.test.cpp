// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include "../../../ds/segment/binary-indexed-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    BinaryIndexedTree<ll> bit(n);
    for (int i = 0; i < n; i++) {
        INT(a);
        bit.add(i, a);
    }
    rep(q) {
        INT(t, l, r);
        if (t)
            print(bit.sum(l, r));
        else
            bit.add(l, r);
    }
}