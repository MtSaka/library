// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/factorize
#include "../../../math/number/pollard-rho.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(q);
    rep(q) {
        LL(x);
        auto ret = factorize(x);
        print(ret.size(), ret);
    }
}