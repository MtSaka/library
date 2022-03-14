#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  cout<<fixed<<setprecision(15);
  geometry::point p1,p2;cin>>p1>>p2;
  int q;cin>>q;
  while(q--){
    geometry::point p;cin>>p;
    auto ans=geometry::reflect(geometry::line(p1,p2),p);
    cout<<ans.x<<" "<<ans.y<<endl;
  }
}