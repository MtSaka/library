#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include"../../template/template.hpp"
#include"../../Math/fps.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  FPS<mod>f(n),g(m);
  cin>>f>>g;
  FPS<mod>q=f/g,r=f%g;
  cout<<q.size()<<" "<<r.size()<<endl;
  cout<<q<<endl;
  cout<<r<<endl;
}