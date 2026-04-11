// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../../../graph/graph-template.hpp"
#include "../../../template/template.hpp"
#include "../../../graph/tree/PMORMQ-lowest-common-ancestor.hpp"

int main() {
    int n, q;
    sc >> n >> q;
    UnweightedGraph g(n);
    rep(i, 1, n) {
        int p;
        sc >> p;
        g.add_edge(i, p);
    }
    PMORMQLCA lca(g);
    lca.build();
    rep(i, q) {
        int u, v;
        sc >> u >> v;
        print(lca.lca(u, v));
    }
}