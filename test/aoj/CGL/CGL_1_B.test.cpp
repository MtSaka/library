// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B
// competitive-verifier: ERROR 1e-6
#include "../../../geometry/geometry.hpp"
#include "../../../template/template.hpp"
int main() {
    geometry::point p1, p2;
    sc >> p1 >> p2;
    INT(q);
    rep(q) {
        geometry::point p;
        sc >> p;
        auto ans = geometry::reflect(geometry::line(p1, p2), p);
        print(ans.x, ans.y);
    }
}