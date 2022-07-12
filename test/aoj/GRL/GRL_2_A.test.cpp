#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include"../../../template/template.hpp"
#include"../../../graph/mst/kruskal.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  Edges<long long>edges(e);
  for(auto &i:edges)cin>>i.from>>i.to>>i.cost;
  auto ans=kruskal(edges,v);
  cout<<ans.cost<<endl;
}