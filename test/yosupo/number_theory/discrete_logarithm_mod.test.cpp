// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
#include "../../../math/modular/mod-log.hpp"
#include "../../../template/template.hpp"
int main() {
    int t;
    sc >> t;
    rep(t) {
        ll x, y, m;
        sc >> x >> y >> m;
        print(discrete_logarithm(x, y, m));
    }
}