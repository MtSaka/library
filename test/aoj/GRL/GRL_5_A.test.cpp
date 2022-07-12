#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include"../../../template/template.hpp"
#include"../../../graph/tree/tree_diameter.hpp"
int main(){
  int n;
  cin>>n;
  TreeDiameter<int>g(n);
  g.read(n-1,0,true);
  cout<<g.build()<<endl;
}