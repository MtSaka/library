// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/polynomial_taylor_shift
#include "../../../math/fps/taylor-shift.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n, c);
    FormalPowerSeries<mint> f(n);
    cin >> f;
    print(taylor_shift(f, mint(c)));
}