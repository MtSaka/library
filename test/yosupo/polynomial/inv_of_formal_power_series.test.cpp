// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/inv_of_formal_power_series
#include "../../../math/fps/fps.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n);
    FormalPowerSeries<mint> fps(n);
    sc >> fps;
    print(fps.inv());
}