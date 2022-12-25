#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  INT(n);
  geometry::polygon p(n);
  rep(i,n)cin>>p[i];
  print(geometry::isconvex(p));
}