#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  int n;
  cin>>n;
  geometry::polygon p(n);
  for(int i=0;i<n;i++)cin>>p[i];
  cout<<geometry::isconvex(p)<<endl;
}