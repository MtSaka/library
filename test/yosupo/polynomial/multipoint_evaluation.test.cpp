// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/multipoint_evaluation
#include "../../../math/fps/fps.hpp"
#include "../../../math/fps/multipoint-evaluation.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n, m);
    FormalPowerSeries<mint> f(n);
    vector<mint> xs(m);
    cin >> f >> xs;
    print(multipoint_evaluation(f, xs));
}