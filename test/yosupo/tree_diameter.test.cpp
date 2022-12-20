#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include"../../template/template.hpp"
#include"../../graph/tree/tree-diameter.hpp"
int main(){
  int n;
  cin>>n;
  TreeDiameter<ll>g(n);
  g.read(n-1,0,true);
  cout<<g.build()<<" "<<g.path.size()+1<<endl;
  cout<<g.path[0].from<<" "<<g.path<<endl;
}