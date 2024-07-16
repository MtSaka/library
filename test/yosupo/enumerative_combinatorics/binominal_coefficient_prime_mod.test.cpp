// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
#include "../../../template/template.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../math/others/combinatorics.hpp"
using Comb = Combinatorics<modint>;
int main() {
    INT(t, m);
    modint::set_mod(m);
    Comb::extend(min(m, 10000000) - 1);
    while (t--) {
        INT(n, k);
        print(Comb::com(n, k));
    }
}