#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include"../../../template/template.hpp"
#include"../../../graph/others/scc.hpp"
int main(){
  int v,e,q;
  cin>>v>>e;
  SCC<>scc(v);
  scc.read(e,0,false,true);
  scc.build();
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<(scc[a]==scc[b])<<endl;
  }
}