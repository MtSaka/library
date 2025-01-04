// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large
#include "../../../template/template.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/fps/compositional-inverse.hpp"
using mint = ModInt<998244353>;
using fps = FormalPowerSeries<mint>;
int main() {
    LL(n);
    fps f(n);
    sc >> f;
    print(composittional_inverse(f));
}
