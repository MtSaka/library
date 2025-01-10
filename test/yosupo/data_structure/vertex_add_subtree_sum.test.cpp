// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum
#include "../../../ds/segment/binary-indexed-tree.hpp"
#include "../../../graph/graph-template.hpp"
#include "../../../graph/tree/heavy-light-decomposition.hpp"
#include "../../../template/template.hpp"

int main() {
    int n, q;
    sc >> n >> q;
    vector<ll> a(n);
    sc >> a;
    Graph<int> g(n);
    rep(i, 1, n) {
        int p;
        sc >> p;
        g.add_edge(i, p);
    }
    HeavyLightDecomposition<int> hld(g);
    BinaryIndexedTree<ll> bit(n);
    rep(i, n) {
        auto [l, r] = hld.get_id(i);
        bit.add(l, a[i]);
    }
    rep(i, q) {
        int t;
        sc >> t;
        if (t == 0) {
            int p;
            ll x;
            sc >> p >> x;
            auto [l, r] = hld.get_id(p);
            bit.add(l, x);
        } else {
            int u;
            sc >> u;
            ll ans = 0;
            hld.subtree_query(u, [&](int l, int r) { ans += bit.sum(l, r); });
            print(ans);
        }
    }
}