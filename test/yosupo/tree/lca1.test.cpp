// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../../../graph/tree/fast-lowest-common-ancestor.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    LCA g(n);
    rep(i, 1, n) {
        INT(u);
        g.add_edge(u, i);
    }
    g.build();
    rep(q) {
        INT(u, v);
        print(g.lca(u, v));
    }
}