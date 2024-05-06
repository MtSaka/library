// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
#include "../../../math/modular/mod-log.hpp"
#include "../../../template/template.hpp"
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, m;
        cin >> x >> y >> m;
        print(discrete_logarithm(x, y, m));
    }
}