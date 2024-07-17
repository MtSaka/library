// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_primes
#include "../../../template/template.hpp"
#include "../../../math/number/prime-sieve.hpp"
int main() {
    LL(n, a, b);
    auto p = IsPrime(n).get_primes();
    vl ans;
    ans.reserve(p.size() / a + 1);
    rep(i, b, p.size(), a) ans.eb(p[i]);
    print(p.size(), ans.size());
    print(ans);
}