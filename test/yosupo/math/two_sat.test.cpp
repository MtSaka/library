// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/two_sat
#include "../../../graph/others/two-sat.hpp"
#include "../../../template/template.hpp"
int main() {
    string s;
    int n, m;
    sc >> s >> s >> n >> m;
    TwoSat ts(n);
    while (m--) {
        int a, b;
        sc >> a >> b >> s;
        ts.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    auto ans = ts.calc();
    if (ans.empty()) fin("s UNSATISFIABLE");
    print("s SATISFIABLE");
    wt << "v ";
    rep(i, n) wt << (ans[i] ? i + 1 : -i - 1) << " ";
    print(0);
}