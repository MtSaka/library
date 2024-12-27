// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/min_of_mod_of_linear
#include "../../../template/template.hpp"
#include "../../../math/number/min-of-mod-linear.hpp"
int main() {
    INT(t);
    rep(t) {
        LL(n, m, a, b);
        print(min_of_mod_linear(n, m, a, b));
    }
}