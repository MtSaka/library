// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_det
#include "../../../math/modular/modint.hpp"
#include "../../../math/others/matrix.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n);
    Matrix<mint> mat(n);
    sc >> mat;
    print(mat.determinant());
}