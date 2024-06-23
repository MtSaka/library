// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
#include "../../../math/number/prime-sieve.hpp"
#include "../../../template/template.hpp"
int main() {
    int n;
    sc >> n;
    IsPrime<ll> ip(100000000);
    int ans = 0;
    while (n--) {
        int a;
        sc >> a;
        ans += ip.is_prime(a);
    }
    print(ans);
}