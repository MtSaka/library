#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"
#include"../../../template/template.hpp"
#include"../../../Geometry/geometry.hpp"
int main(){
  int n;
  cin>>n;
  geometry::polygon pol(n);
  for(int i=0;i<n;i++)cin>>pol[i];
  long double ans=geometry::area(pol);
  cout<<fixed<<setprecision(1)<<ans<<endl;
}