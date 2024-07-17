// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind
#include "../../../ds/union-find/union-find.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, q;
    sc >> n >> q;
    UnionFind d(n);
    rep(q) {
        int t, u, v;
        sc >> t >> u >> v;
        if (t)
            print(d.same(u, v));
        else
            d.merge(u, v);
    }
}