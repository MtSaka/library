// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod
#include "../../../math/modular/mod-sqrt.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(t);
    rep(t) {
        LL(y, p);
        print(mod_sqrt(y, p));
    }
}