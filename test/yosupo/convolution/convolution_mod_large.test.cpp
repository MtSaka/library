// DON'T VERIFY(Testcases Too Large) competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/convolution_mod_large
#include "../../../template/template.hpp"
#include "../../../math/convolution/large-convolution.hpp"
using mint = ModInt<998244353>;
int main() {
    INT(n, m);
    vector<mint> a(n), b(m);
    sc >> a >> b;
    print(convolution_large(a, b));
}