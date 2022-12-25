#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include"../../../template/template.hpp"
#include"../../../graph/tree/RMQ_lowest_common_ancestor.hpp"
int main(){
  INT(n);
  RMQ_LCA g(n);
  rep(i,n){
    INT(k);
    while(k--){
      INT(j);
      g.add_edge(i,j,false);
    }
  }
  g.build();
  INT(q);
  while(q--){
    INT(a,b);
    print(g.lca(a,b));
  }
}