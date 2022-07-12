#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include"../../../template/template.hpp"
#include"../../../graph/others/topological_sort.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  graph<int>g(v);
  g.read(e,0,false,true);
  for(auto i:topological_sort<int>(g).get())cout<<i<<endl;
}