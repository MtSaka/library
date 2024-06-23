// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
#include "../../../math/convolution/min-plus-convolution-convex.hpp"
#include "../../../template/template.hpp"

int main() {
    INT(n, m);
    vector<int> a(n), b(m);
    sc >> a >> b;
    print(min_plus_convolution_convex(a, b));
}