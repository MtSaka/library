// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  INT(q);
  while(q--){
    geometry::point p1,p2,q1,q2;
    cin>>p1>>p2>>q1>>q2;
    geometry::line a(p1,p2),b(q1,q2);
    int ans=geometry::line_place(a,b);
    if(ans==1)ans=2;
    else if(ans==3)ans=1;
    print(ans);
  }
}