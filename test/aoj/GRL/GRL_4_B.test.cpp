#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"
#include"../../../template/template.hpp"
#include"../../../graph/others/topological-sort.hpp"
int main(){
  INT(v,e);
  Graph g(v);
  g.read(e,0,false,true);
  for(auto i:TopologicalSort<int>(g).get())print(i);
}