// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
#include"../../../template/template.hpp"
#include"../../../graph/shortest-path/warshall-floyd.hpp"
int main(){
  INT(v,e);
  Graph<ll>g(v);
  g.read(e,0,true,true);
  auto d=warshall_floyd(g);
  rep(i,v){
    if(d[i][i]<0){
      print("NEGATIVE CYCLE");
      return 0;
    }
  }
  for(auto k:d)for(int i=0;i<k.size();i++)cout<<(k[i]==numeric_limits<long long>::max()/2?"INF":to_string(k[i]))<<(i==k.size()-1?"\n":" ");
}