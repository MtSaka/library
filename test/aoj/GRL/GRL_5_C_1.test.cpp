// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
#include "../../../graph/tree/fast-lowest-common-ancestor.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n);
    LCA g(n);
    rep(i, n) {
        INT(k);
        while (k--) {
            INT(j);
            g.add_edge(i, j);
        }
    }
    g.build();
    INT(q);
    rep(q) {
        INT(a, b);
        print(g.lca(a, b));
    }
}