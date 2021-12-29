#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#pragma once
#include"../../../template/template.hpp"
#include"../../../Graph/bellman_ford.hpp"
#include"../../../Graph/negative_cycle.hpp"
int main(){
  int v,e,r;
  cin>>v>>e>>r;
  Graph<long long>g(v);
  g.read(e,0,true,true);
  if(negative_cycle(g)){
    cout<<"NEGATIVE CYCLE"<<endl;
    return 0;
  }
  auto d=bellman_ford(g,r);
  for(auto i:d)cout<<(i==numeric_limits<long long>::max()/2?"INF":to_string(i))<<endl;
}