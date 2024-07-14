// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_triangles
#include "../../../template/template.hpp"
#include "../../../graph/others/enumerate-triangles.hpp"
#include "../../../math/modular/modint.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n, m);
    vector<mint> x(n);
    sc >> x;
    UnweightedGraph g(n);
    g.read(m, 0);
    mint ans = 0;
    auto f = [&x, &ans](int i, int j, int k) {
        ans += x[i] * x[j] * x[k];
    };
    enumerate_triangles(g, f);
    print(ans);
}