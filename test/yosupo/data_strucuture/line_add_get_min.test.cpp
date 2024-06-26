// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/line_add_get_min
#include "../../../ds/cht/convex-hull-trick.hpp"
#include "../../../template/template.hpp"
int main() {
    ConvexHullTrick cht;
    INT(n, q);
    rep(i, n) {
        LL(a, b);
        cht.add_line(a, b);
    }
    rep(i, q) {
        INT(t);
        if (t == 0) {
            LL(a, b);
            cht.add_line(a, b);
        } else {
            LL(x);
            print(cht.get_min(x));
        }
    }
}