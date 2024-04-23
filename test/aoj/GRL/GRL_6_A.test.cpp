// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
#include"../../../template/template.hpp"
#include"../../../graph/flow/dinic.hpp"
int main(){
  INT(v,e);
  Dinic<int>g(v);
  rep(i,e){
    INT(a,b,c);
    g.add_edge(a,b,c);
  }
  print(g.max_flow(0,v-1));
}