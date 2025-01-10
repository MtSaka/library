// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_parallel_unionfind
#include "../../../template/template.hpp"
#include "../../../ds/union-find/range-parallel-union-find.hpp"
#include "../../../math/modular/modint.hpp"
using mint = ModInt<998244353>;

int main() {
    INT(n, q);
    vector<mint> x(n);
    sc >> x;
    RangeParallelUnionFind uf(n);
    mint ans = 0;
    auto f = [&](int i, int j) {
        ans += x[i] * x[j];
        x[i] += x[j];
    };
    rep(q) {
        INT(k, a, b);
        uf.range_merge(a, b, k);
        print(ans);
    }
}