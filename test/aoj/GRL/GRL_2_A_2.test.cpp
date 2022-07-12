#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include"../../../template/template.hpp"
#include"../../../graph/mst/prim.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  graph<>g(v);
  g.read(e,0,true);
  cout<<prim(g).cost<<endl;
}