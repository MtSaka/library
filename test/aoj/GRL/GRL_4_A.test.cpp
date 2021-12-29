#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"
#include"../../../template/template.hpp"
#include"../../../Graph/detect_cycle.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  Graph<int>g(v);
  g.read(e,0,false,true);
  cout<<detect_cycle(g)<<endl;
}