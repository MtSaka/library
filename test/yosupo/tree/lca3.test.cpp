// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include "../../../graph/graph-template.hpp"
#include "../../../graph/tree/heavy-light-decomposition.hpp"
#include "../../../template/template.hpp"

int main() {
    int n, q;
    sc >> n >> q;
    UnweightedGraph g(n);
    rep(i, 1, n) {
        int p;
        sc >> p;
        g.add_edge(i, p);
    }
    HeavyLightDecomposition<UnweightedEdge> hld(g);
    rep(i, q) {
        int u, v;
        sc >> u >> v;
        print(hld.lca(u, v));
    }
}