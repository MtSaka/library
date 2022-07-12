#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include"../../../template/template.hpp"
#include"../../../Graph/mst/kruskal.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  edges<long long>ed(e);
  for(auto &i:ed)cin>>i.from>>i.to>>i.cost;
  cout<<kruskal(ed,v).cost<<endl;
}