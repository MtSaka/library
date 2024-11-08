// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/pow_of_matrix
#include "../../../template/template.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../math/others/matrix.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n);
    LL(k);
    Matrix<mint> mat(n);
    sc >> mat;
    mat ^= k;
    rep(i, n) print(mat[i]);
}