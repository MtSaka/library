#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../../template/template.hpp"
#include"../../../graph/tree/doubling-lowest-common-ancestor.hpp"
int main(){
  INT(n,q);
  DoublingLCA g(n);
  rep(i,1,n){
    INT(u);
    g.add_edge(u,i,false);
  }
  g.build();
  while(q--){
    INT(u,v);
    print(g.lca(u,v));
  }
}