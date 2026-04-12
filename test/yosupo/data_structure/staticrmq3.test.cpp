// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/staticrmq
#include "../../../template/template.hpp"
#include "../../../graph/tree/PMORMQ-lowest-common-ancestor.hpp"
#include "../../../graph/tree/catersian-tree.hpp"

int main() {
    INT(n, q);
    vi a(n);
    sc >> a;
    CatersianTree ct(a);
    auto g = ct.get_graph();
    int r = ct.get_root();
    PMORMQLCA lca(g);
    lca.build(r);
    while (q--) {
        int u, v;
        sc >> u >> v;
        v--;
        print(a[lca.lca(u, v)]);
    }
}