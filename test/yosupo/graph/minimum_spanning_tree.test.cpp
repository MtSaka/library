// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/minimum_spanning_tree
#include "../../../template/template.hpp"
#include "../../../graph/mst/kruskal.hpp"

int main() {
    INT(n, m);
    Edges<ll> es(m);
    rep(i, m) {
        INT(a, b);
        LL(c);
        es[i] = Edge(a, b, c, i);
    }
    auto res = kruskal(es, n);
    print(res.first);
    rep(i, res.second.size()) pr << res.second[i].idx << " \n"[i == res.second.size() - 1];
}