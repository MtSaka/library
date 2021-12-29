#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include"../../../template/template.hpp"
#include"../../../Graph/kruskal.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  Graph<long long>g(v);
  g.read(e,0,true);
  auto ans=kruskal(g,v);
  cout<<ans.cost<<endl;
}