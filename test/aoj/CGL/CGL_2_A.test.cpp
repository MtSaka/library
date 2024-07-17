// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A
#include "../../../geometry/geometry.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(q);
    rep(q) {
        geometry::point p1, p2, q1, q2;
        sc >> p1 >> p2 >> q1 >> q2;
        geometry::line a(p1, p2), b(q1, q2);
        int ans = geometry::line_place(a, b);
        if (ans == 1)
            ans = 2;
        else if (ans == 3)
            ans = 1;
        print(ans);
    }
}