// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C
#include "../../../geometry/geometry.hpp"
#include "../../../template/template.hpp"
int main() {
    geometry::point p1, p2;
    sc >> p1 >> p2;
    INT(q);
    rep(q) {
        geometry::point p;
        sc >> p;
        int dir = geometry::ccw(p, p1, p2);
        if (dir == 1)
            print("COUNTER_CLOCKWISE");
        else if (dir == -1)
            print("CLOCKWISE");
        else if (p == p1 || p == p2 || dir == 2)
            print("ON_SEGMENT");
        else if (dir == -2)
            print("ONLINE_BACK");
        else
            print("ONLINE_FRONT");
    }
}