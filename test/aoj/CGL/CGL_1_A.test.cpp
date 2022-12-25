#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
#define ERROR 1e-6
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  cout<<fixed<<setprecision(15);
  geometry::point p1,p2;cin>>p1>>p2;
  INT(q);
  while(q--){
    geometry::point q;
    cin>>q;
    auto ans=geometry::project(geometry::line(p1,p2),q);
    print(ans.x,ans.y);
  }
}