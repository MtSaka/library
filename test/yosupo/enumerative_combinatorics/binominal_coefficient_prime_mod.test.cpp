// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
#include "../../../template/template.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../math/others/combinatorics.hpp"
Combinatorics<modint> comb;
int main() {
    INT(t, m);
    modint::set_mod(m);
    comb.fac(min(m, 10000000) - 1);
    while (t--) {
        INT(n, k);
        print(comb.com(n, k));
    }
}