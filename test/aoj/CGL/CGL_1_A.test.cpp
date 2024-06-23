// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A
// competitive-verifier: ERROR 1e-6
#include "../../../geometry/geometry.hpp"
#include "../../../template/template.hpp"
int main() {
    geometry::point p1, p2;
    sc >> p1 >> p2;
    INT(q);
    while (q--) {
        geometry::point q;
        sc >> q;
        auto ans = geometry::project(geometry::line(p1, p2), q);
        print(ans.x, ans.y);
    }
}