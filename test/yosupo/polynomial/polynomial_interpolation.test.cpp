// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_interpolation
#include "../../../math/fps/fps.hpp"
#include "../../../math/fps/polynomial-interpolation.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n);
    vector<mint> xs(n), ys(n);
    cin >> xs >> ys;
    print(polynomial_interpolation(xs, ys));
}