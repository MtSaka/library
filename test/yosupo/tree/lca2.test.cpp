// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../../../graph/tree/RMQ_lowest_common_ancestor.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    RMQ_LCA g(n);
    for (int i = 1; i < n; i++) {
        INT(u);
        g.add_edge(u, i);
    }
    g.build();
    while (q--) {
        INT(u, v);
        print(g.lca(u, v));
    }
}