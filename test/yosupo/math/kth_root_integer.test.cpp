// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/kth_root_integer
#include "../../../math/number/kth-root-integer.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(t);
    while (t--) {
        uint64_t a;
        sc >> a;
        INT(k);
        print(kth_root_integer(a, k));
    }
}