// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
#include "../../../ds/segment/segment-tree-beats.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, q;
    sc >> n >> q;
    vl a(n);
    sc >> a;
    SegmentTreeBeats<ll> seg(a);
    rep(q) {
        int t;
        sc >> t;
        if (t == 0) {
            int l, r;
            ll x;
            sc >> l >> r >> x;
            seg.range_chmin(l, r, x);
        } else if (t == 1) {
            int l, r;
            ll x;
            sc >> l >> r >> x;
            seg.range_chmax(l, r, x);
        } else if (t == 2) {
            int l, r;
            ll x;
            sc >> l >> r >> x;
            seg.range_add(l, r, x);
        } else {
            int l, r;
            sc >> l >> r;
            print(seg.range_sum(l, r));
        }
    }
}