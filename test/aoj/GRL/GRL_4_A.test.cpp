// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
#include "../../../graph/others/detect-cycle.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(v, e);
    Graph<int> g(v);
    g.read(e, 0, false, true);
    print(detect_cycle(g));
}