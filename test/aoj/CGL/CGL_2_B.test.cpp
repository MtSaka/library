// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  INT(q);
  while(q--){
    geometry::point p1,p2,q1,q2;
    cin>>p1>>p2>>q1>>q2;
    geometry::segment a(p1,p2),b(q1,q2);
    print(geometry::intersect(a,b));
  }
}