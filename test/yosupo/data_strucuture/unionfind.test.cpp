// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind
#include "../../../ds/union-find/union-find.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, q;
    cin >> n >> q;
    UnionFind d(n);
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t)
            print(d.same(u, v));
        else
            d.merge(u, v);
    }
}