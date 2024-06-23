// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product
#include "../../../math/modular/modint.hpp"
#include "../../../math/others/matrix.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n, m, k);
    Matrix<mint> a(n, m), b(m, k);
    sc >> a >> b;
    a *= b;
    rep(i, n) print(a[i]);
}