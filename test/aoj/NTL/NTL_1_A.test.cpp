// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
#include "../../../math/number/prime-factor.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n);
    pr << n << ": " << prime_factor(n) << "\n";
}