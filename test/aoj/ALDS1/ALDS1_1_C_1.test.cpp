// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
#include "../../../template/template.hpp"
int main() {
    int q;
    sc >> q;
    int ans = 0;
    while (q--) {
        int x;
        sc >> x;
        ans += is_prime(x);
    }
    print(ans);
}