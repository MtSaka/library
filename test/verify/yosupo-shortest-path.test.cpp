#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../template/template.cpp"
#include "../../Graph/dijkstra.cpp"
int main(){
  INT(n,m,s,t);
  Graph g(n);
  for(int i=0;i<m;i++){
    INT(a,b,c);
    Edge e;
    e.to=b,e.cost=c;
    g[a].push_back(e);
  }
  auto ans=dijkstra_path(g,s,t);
  if(ans.first==-1)fin(-1);
  print(ans.first,ans.second.size()-1);
  rep(i,ans.second.size()-1){
    print(ans.second[i],ans.second[i+1]);
  }
}