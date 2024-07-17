// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sum_of_floor_of_linear
#include "../../../template/template.hpp"
#include "../../../math/number/floor-sum.hpp"
int main() {
    INT(t);
    rep(t){
        LL(n, m, a, b);
        print(floor_sum(n, m, a, b));
    }
}