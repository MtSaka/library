#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/dsu.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  dsu d(n);
  while(q--){
    int t,x,y;
    cin>>t>>x>>y;
    if(t==0)d.merge(x,y);
    else print(d.same(x,y));
  }
}