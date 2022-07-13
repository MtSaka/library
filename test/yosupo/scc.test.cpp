#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include"../../template/template.hpp"
#include"../../Graph/others/scc.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  SCC scc(n);
  scc.read(m,0,false,true);
  scc.build();
  auto ret=scc.scc();
  cout<<ret.size()<<endl;
  for(auto&p:ret)cout<<p.size()<<" "<<p<<endl;
}