#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include"../../../template/template.hpp"
#include"../../../Graph/shortest_path/bellman_ford.hpp"
int main(){
  int v,e,r;
  cin>>v>>e>>r;
  graph<long long>g(v);
  g.read(e,0,true,true);
  auto d=bellman_ford(g,r);
  if(count(d.begin(),d.end(),-numeric_limits<long long>::max()/2)){
    cout<<"NEGATIVE CYCLE"<<endl;
    return 0;
  }
  for(auto i:d)cout<<(i==numeric_limits<long long>::max()/2?"INF":to_string(i))<<endl;
}