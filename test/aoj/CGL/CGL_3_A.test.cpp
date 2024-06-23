// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A
#include "../../../geometry/geometry.hpp"
#include "../../../template/template.hpp"
int main() {
    int n;
    sc >> n;
    geometry::polygon pol(n);
    for (int i = 0; i < n; i++) sc >> pol[i];
    long double ans = geometry::area(pol);
    pr.set_decimal_precision(1);
    pr << ans << '\n';
}