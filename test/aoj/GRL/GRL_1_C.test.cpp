#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#pragma once
#include"../../../template/template.hpp"
#include"../../../Graph/warshall_floyd.hpp"
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
  auto d=warshall_floyd(g);
  for(auto k:d)for(int i=0;i<k.size();i++)cout<<(k[i]==numeric_limits<long long>::max()/2?"INF":to_string(k[i]))<<(i==k.size()-1?"\n":" ");
}