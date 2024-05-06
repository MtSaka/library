// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/jump_on_tree
#include "../../../graph/graph-template.hpp"
#include "../../../graph/tree/fast-lowest-common-ancestor.hpp"
#include "../../../template/template.hpp"

int main() {
    INT(n, q);
    UnweightedGraph g(n);
    g.read(n - 1, 0);
    LCA lca(g);
    lca.build();
    rep(q) {
        INT(u, v, k);
        print(lca.jump(u, v, k));
    }
}