#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include"../../../template/template.hpp"
#include"../../../graph/mst/prim.hpp"
int main(){
  INT(v,e);
  Graph g(v);
  g.read(e,0,true);
  print(prim(g).cost);
}