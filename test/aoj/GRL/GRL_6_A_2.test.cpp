#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include"../../../template/template.hpp"
#include"../../../graph/flow/ford-fulkerson.hpp"
int main(){
  INT(v,e);
  FordFulkerson<int>g(v);
  rep(i,e){
    INT(a,b,c);
    g.add_edge(a,b,c);
  }
  print(g.max_flow(0,v-1));
}