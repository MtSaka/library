#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include"../../../template/template.hpp"
#include"../../../graph/flow/for-fulkerson.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  FordFulkerson<int>g(v);
  for(int i=0;i<e;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g.add_edge(a,b,c);
  }
  cout<<g.max_flow(0,v-1)<<endl;
}