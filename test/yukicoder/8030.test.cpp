// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/8030
#include "../../math/number/miller-rabin.hpp"
#include "../../template/template.hpp"
int main() {
    INT(n);
    while (n--) {
        LL(x);
        print(x, is_prime_fast(x));
    }
}