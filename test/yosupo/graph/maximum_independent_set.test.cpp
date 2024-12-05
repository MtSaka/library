// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/maximum_independent_set
#include "../../../template/template.hpp"
#include "../../../graph/others/maximum-independet-set.hpp"
int main() {
    INT(n, m);
    vector<vi> g(n);
    rep(m) {
        INT(u, v);
        g[u].eb(v);
        g[v].eb(u);
    }
    auto ans = MaximumIndependentSet(g);
    print(popcnt(ans));
    rep(i, n) if ((ans >> i) & 1) pr << i << " ";
    pr << endl;
}