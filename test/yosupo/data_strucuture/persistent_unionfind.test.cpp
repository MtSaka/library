// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/persistent_unionfind
#include "../../../ds/union-find/persistent-union-find.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    using node = PersistentUnionFind::node;
    PersistentUnionFind d(n);
    vector<node*> g(q + 1);
    g[0] = d.get_root();
    rep(i, 1, q + 1) {
        INT(t, k, u, v);
        k++;
        if (t == 0)
            g[i] = d.merge(u, v, g[k]).second;
        else
            print(d.same(u, v, g[k]));
    }
}