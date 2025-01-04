// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/composition_of_formal_power_series_large
#include "../../../template/template.hpp"
#include "../../../math/fps/fps.hpp"
#include "../../../math/fps/composition.hpp"

using mint = ModInt<998244353>;
using fps = FormalPowerSeries<mint>;
int main() {
    LL(n);
    fps f(n), g(n);
    sc >> f >> g;
    print(composite(g, f));
}