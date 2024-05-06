// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/scc
#include "../../../graph/others/scc.hpp"

#include "../../../template/template.hpp"
int main() {
    INT(n, m);
    SCC scc(n);
    scc.read(m, 0, false, true);
    scc.build();
    auto ret = scc.scc();
    print(ret.size());
    for (auto& p : ret) print(p.size(), p);
}