#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_C"
#include"../../../template/template.hpp"
#include"../../../Geometry/geometry.hpp"
int main(){
  int n;
  cin>>n;
  geometry::polygon pol(n);
  for(int i=0;i<n;i++)cin>>pol[i];
  int q;
  cin>>q;
  while(q--){
    geometry::point p;cin>>p;
    int ans=geometry::in_polygon(p,pol);
    if(ans==1)ans=2;
    else if(ans==2)ans=1;
    cout<<ans<<endl;
  }
}