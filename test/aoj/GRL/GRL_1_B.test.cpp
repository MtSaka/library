// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
#include"../../../template/template.hpp"
#include"../../../graph/shortest-path/bellman-ford.hpp"
int main(){
  INT(v,e,r);
  Graph<ll>g(v);
  g.read(e,0,true,true);
  auto d=bellman_ford(g,r);
  if(count(d.begin(),d.end(),-numeric_limits<long long>::max()/2)){
    print("NEGATIVE CYCLE");
    return 0;
  }
  for(auto i:d)print(i==numeric_limits<long long>::max()/2?"INF":to_string(i));
}