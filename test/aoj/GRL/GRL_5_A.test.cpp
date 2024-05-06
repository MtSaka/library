// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
#include "../../../graph/tree/tree-diameter.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n);
    TreeDiameter<int> g(n);
    g.read(n - 1, 0, true);
    print(g.build());
}