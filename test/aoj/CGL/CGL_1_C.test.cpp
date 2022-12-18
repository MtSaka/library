#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#include"../../../template/template.hpp"
#include"../../../geometry/geometry.hpp"
int main(){
  geometry::point p1,p2;
  cin>>p1>>p2;
  int q;
  cin>>q;
  while(q--){
    geometry::point p;cin>>p;
    int dir=geometry::ccw(p,p1,p2);
    if(dir==1)cout<<"COUNTER_CLOCKWISE"<<endl;
    else if(dir==-1)cout<<"CLOCKWISE"<<endl;
    else if(p==p1||p==p2||dir==2)cout<<"ON_SEGMENT"<<endl;
    else if(dir==-2)cout<<"ONLINE_BACK"<<endl;
    else cout<<"ONLINE_FRONT"<<endl;
  }
}