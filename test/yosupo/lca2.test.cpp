#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../template/template.hpp"
#include"../../graph/tree/RMQ_lowest_common_ancestor.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  RMQ_LCA g(n);
  for(int i=1;i<n;i++){
    int u;
    cin>>u;
    g.add_edge(u,i,false);
  }
  g.build();
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<g.lca(u,v)<<endl;
  }
}