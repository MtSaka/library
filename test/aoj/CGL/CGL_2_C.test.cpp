// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_C
// competitive-verifier: ERROR 1e-6
#include "../../../geometry/geometry.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(q);
    while (q--) {
        geometry::point p1, p2, q1, q2;
        sc >> p1 >> p2 >> q1 >> q2;
        geometry::line a(p1, p2), b(q1, q2);
        auto ans = geometry::crosspoint(a, b);
        print(ans.x, ans.y);
    }
}