#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 1e-6
#include"../../../template/template.hpp"
#include"../../../Geometry/geometry.hpp"
int main(){
  cout<<fixed<<setprecision(15);
  int q;
  cin>>q;
  while(q--){
    geometry::point p1,p2,q1,q2;
    cin>>p1>>p2>>q1>>q2;
    geometry::segment a(p1,p2),b(q1,q2);
    auto ans=dist(a,b);
    cout<<ans<<endl;
  }
}