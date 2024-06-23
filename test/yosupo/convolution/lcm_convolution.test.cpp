// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lcm_convolution
#include "../../../math/convolution/lcm-convolution.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../template/template.hpp"
using mint = ModInt<998244353>;
int main() {
    int n;
    sc >> n;
    vector<mint> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) sc >> a[i];
    for (int i = 1; i <= n; i++) sc >> b[i];
    auto ans = lcm_convolution(a, b);
    ans.erase(ans.begin());
    print(ans);
}