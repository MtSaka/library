// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/pow_of_formal_power_series
#include "../../../math/fps/fps.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n);
    LL(m);
    FormalPowerSeries<mint> f(n);
    cin >> f;
    print(f.pow(m));
}