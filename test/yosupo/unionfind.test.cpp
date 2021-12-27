#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include"../../template/template.hpp"
#include"../../Data_Structure/dsu.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  dsu d(n);
  while(q--){
    int t,u,v;
    cin>>t>>u>>v;
    if(t)print(d.same(u,v));
    else d.merge(u,v);
  }
}