#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include"../../../template/template.hpp"
#include"../../../graph/others/scc.hpp"
int main(){
  INT(n,m);
  SCC scc(n);
  scc.read(m,0,false,true);
  scc.build();
  auto ret=scc.scc();
  print(ret.size());
  for(auto&p:ret)print(p.size(),p);
}