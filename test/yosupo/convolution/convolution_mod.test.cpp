// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/convolution_mod
#include "../../../math/convolution/convolution.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, m);
    vector<ModInt<998244353>> a(n), b(m);
    scan(a, b);
    print(convolution(a, b));
}