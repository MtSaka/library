// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence
#include "../../../template/template.hpp"
#include "../../../math/fps/polynomial-interpolation-gemoetric.hpp"
using mint = ModInt<998244353>;
using fps = FormalPowerSeries<mint>;
int main() {
    LL(n);
    mint a, r;
    sc >> a >> r;
    vector<mint> y(n);
    sc >> y;
    print(polynomial_interpolation_gemoetric(y, a, r));
}