// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
#include "../../../graph/mst/prim.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(v, e);
    Graph<ll> g(v);
    g.read(e, 0, true, false);
    print(prim(g).first);
}