#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include"../../template/template.hpp"
#include"../../Graph/dijkstra_path.hpp"
int main(){
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  Graph<long long>g(n);
  g.read(m,0,true,true);
  auto d=dijkstra_path(g,s,t);
  if(d.first==-1){
    cout<<d.first<<endl;
    return 0;
  }
  cout<<d.first<<" "<<d.second.size()-1<<endl;
  for(int i=0;i<d.second.size()-1;i++)cout<<d.second[i]<<" "<<d.second[i+1]<<endl;
}