#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include"../../template/template.hpp"
#include"../../Graph/others/scc.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  SCC scc(n);
  scc.read(m,0,false,true);
  scc.build();
  cout<<scc.group.size()<<endl;
  for(auto&p:scc.group)cout<<p.size()<<" "<<p<<endl;
}