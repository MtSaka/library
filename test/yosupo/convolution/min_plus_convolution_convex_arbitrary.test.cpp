// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
#include "../../../math/convolution/min-plus-convolution.hpp"
#include "../../../template/template.hpp"

int main() {
    INT(n, m);
    vi a(n), b(m);
    cin >> a >> b;
    print(min_plus_convolution(b, a));
}