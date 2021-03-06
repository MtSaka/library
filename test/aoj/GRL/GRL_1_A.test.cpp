#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include"../../../template/template.hpp"
#include"../../../Graph/shortest_path/dijkstra.hpp"
int main(){
  int v,e,r;
  cin>>v>>e>>r;
  graph<long long>g(v);
  g.read(e,0,true,true);
  auto d=dijkstra(g,r);
  for(auto i:d)cout<<(i==numeric_limits<long long>::max()/2?"INF":to_string(i))<<endl;
}