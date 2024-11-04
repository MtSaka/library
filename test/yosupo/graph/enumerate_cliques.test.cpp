// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_cliques
#include "../../../template/template.hpp"
#include "../../../graph/others/enumerate-cliques.hpp"
#include "../../../math/modular/modint.hpp"
using mint = ModInt<998244353>;

int main() {
    INT(n, m);
    vector<mint> x(n);
    sc >> x;
    vector<vector<int>> g(n);
    rep(m) {
        INT(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    mint ans = 0;
    auto f = [&](const vector<int>& c) -> void {
        mint tmp = 1;
        for (auto& e : c) tmp *= x[e];
        ans+=tmp;
    };
    EnumerateCliques(g, f);
    print(ans);
}