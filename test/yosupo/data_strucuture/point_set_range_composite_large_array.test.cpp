// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite_large_array
#include "../../../template/template.hpp"
#include "../../../ds/segment/segment-tree.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../others/monoid2.hpp"
using mint = ModInt<998244353>;
using T = pair<mint, mint>;

int main() {
    INT(n, q);
    vector<array<int, 4>> query(q);
    compressor<int> press;
    for (auto& qu : query) {
        sc >> qu;
        if (qu[0] == 0) press.push_back(qu[1]);
    }
    press.build();
    SegmentTree<Monoid::Composite<mint>> seg(press.size());
    for (auto& qu : query) {
        if (qu[0] == 0) {
            int id = press.get_index(qu[1]);
            seg.set(id, T{qu[2], qu[3]});
        } else {
            const int l = press.get_index(qu[1]);
            const int r = press.get_index(qu[2]);
            const auto [a, b] = seg.prod(l, r);
            print(a * qu[3] + b);
        }
    }
}