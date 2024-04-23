// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  INT(n);
  geometry::polygon pol(n);
  rep(i,n)cin>>pol[i];
  INT(q);
  while(q--){
    geometry::point p;cin>>p;
    int ans=geometry::in_polygon(p,pol);
    if(ans==1)ans=2;
    else if(ans==2)ans=1;
    print(ans);
  }
}