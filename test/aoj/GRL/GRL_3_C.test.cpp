// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
#include "../../../graph/others/scc.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(v, e);
    SCC scc(v);
    scc.read(e, 0, false, true);
    scc.build();
    INT(q);
    while (q--) {
        INT(a, b);
        print(scc[a] == scc[b]);
    }
}