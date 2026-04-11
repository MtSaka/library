// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../../../graph/tree/RMQ-lowest-common-ancestor.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RMQLCA g(n);
    for (int i = 1; i < n; i++) {
        INT(u);
        g.add_edge(u, i);
    }
    g.build();
    rep(q) {
        INT(u, v);
        print(g.lca(u, v));
    }
}