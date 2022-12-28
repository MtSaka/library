#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include"../../../template/template.hpp"
#include"../../../graph/tree/tree-diameter.hpp"
int main(){
  INT(n);
  TreeDiameter<ll>g(n);
  g.read(n-1,0,true);
  auto ans=g.build();
  print(ans,g.path.size()+1);
  print(g.path[0].from,g.path);
}