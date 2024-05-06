// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sqrt_of_formal_power_series
#include "../../../math/fps/fps.hpp"
#include "../../../math/modular/mod-sqrt.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n);
    FormalPowerSeries<mint> f(n);
    cin >> f;
    auto get_sqrt = [&](mint x) -> mint { return mint(mod_sqrt(x.get(), 998244353)); };
    f = f.sqrt(get_sqrt);
    if (f.empty())
        print(-1);
    else {
        print(f);
    }
}