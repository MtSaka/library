// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/counting_primes
#include "../../../template/template.hpp"
#include "../../../math/number/prime-count.hpp"
int main() {
    LL(n);
    print(prime_count(n));
}