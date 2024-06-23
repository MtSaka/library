// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
#include "../../../graph/mst/kruskal.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(v, e);
    Edges<ll> ed(e);
    for (auto& i : ed) sc >> i.from >> i.to >> i.cost;
    print(kruskal(ed, v).first);
}