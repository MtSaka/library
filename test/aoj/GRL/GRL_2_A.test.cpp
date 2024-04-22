#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include"../../../template/template.hpp"
#include"../../../graph/mst/kruskal.hpp"
int main(){
  INT(v,e);
  Edges<ll>ed(e);
  for(auto &i:ed)cin>>i.from>>i.to>>i.cost;
  print(kruskal(ed,v).first);
}