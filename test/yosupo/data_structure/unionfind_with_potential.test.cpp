// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind_with_potential
#include "../../../template/template.hpp"
#include "../../../ds/union-find/weighted-union-find.hpp"
#include "../../../math/modular/modint.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n, q);
    WeightedUnionFind<Monoid::Sum<mint>> uf(n);
    rep(q) {
        INT(t, x, y);
        if (t == 0) {
            mint a;
            sc >> a;
            if (!uf.merge(x, y, a).second)
                print(0);
            else
                print(1);
        } else {
            if (!uf.same(x, y))
                print(-1);
            else
                print(uf.diff(x, y));
        }
    }
}