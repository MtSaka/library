// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
#include "../../../graph/tree/rerooting.hpp"
#include "../../../template/template.hpp"
long long f(long long a, long long b) {
    return max(a, b);
}
long long g(long long a, ReRooting<long long>::Edge b) {
    return a + b.cost;
}
int main() {
    INT(n);
    ReRooting<ll> r(n, f, g);
    for (int i = 0; i < n - 1; i++) {
        INT(s, t);
        LL(w);
        r.add_edge(s, t, w);
    }
    auto ans = r.solve();
    for (auto i : ans) print(i);
}