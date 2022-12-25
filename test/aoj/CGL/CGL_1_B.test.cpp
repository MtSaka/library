#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR 1e-6
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  cout<<fixed<<setprecision(15);
  geometry::point p1,p2;cin>>p1>>p2;
  INT(q);
  while(q--){
    geometry::point p;cin>>p;
    auto ans=geometry::reflect(geometry::line(p1,p2),p);
    print(ans.x,ans.y);
  }
}