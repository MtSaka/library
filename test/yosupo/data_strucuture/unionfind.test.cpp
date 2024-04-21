#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include"../../../template/template.hpp"
#include"../../../ds/union-find/union-find.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  UnionFind d(n);
  while(q--){
    int t,u,v;
    cin>>t>>u>>v;
    if(t)print(d.same(u,v));
    else d.merge(u,v);
  }
}