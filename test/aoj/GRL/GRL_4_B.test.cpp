#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include"../../../template/template.hpp"
#include"../../../Graph/topological_sort.hpp"
int main(){
  int v,e;
  cin>>v>>e;
  Graph<int>g(v);
  g.read(e,0,false,true);
  vector<int>order=t_sort(g);
  for(auto &i:order)cout<<i<<endl;
}