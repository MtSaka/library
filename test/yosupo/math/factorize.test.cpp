// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/factorize
#include "../../../math/number/pollard-rho.hpp"
#include "../../../template/template.hpp"
int main() {
    int q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;
        auto ret = factorize(x);
        print(ret.size(), ret);
    }
}