#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include"../../../template/template.hpp"
#include"../../../graph/shortest-path/dijkstra-path.hpp"
int main(){
  INT(n,m,s,t);
  Graph<ll>g(n);
  g.read(m,0,true,true);
  auto d=dijkstra_path(g,s,t);
  if(d.first==-1){
    print(d.first);
    return 0;
  }
  print(d.firstkd.second.size()-1);
  rep(i,d.second.size()-1)print(d.second[i],d.second[i+1]);
}