// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/lca
#include"../../../template/template.hpp"
#include"../../../graph/tree/fast-lowest-common-ancestor.hpp"
int main(){
  INT(n,q);
  LCA g(n);
  rep(i,1,n){
    INT(u);
    g.add_edge(u,i);
  }
  g.build();
  while(q--){
    INT(u,v);
    print(g.lca(u,v));
  }
}