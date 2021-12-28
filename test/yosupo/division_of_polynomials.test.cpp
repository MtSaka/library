#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include"../../template/template.hpp"
#include"../../Math/fps.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  vector<modint<mod>>a(n),b(m);
  cin>>a>>b;
  FPS<mod>f(a),g(b);
  FPS<mod>q=f/g,r=f%g;
  cout<<q.size()<<" "<<r.size()<<endl;
  cout<<q.val<<endl;
  cout<<r.val<<endl;
}