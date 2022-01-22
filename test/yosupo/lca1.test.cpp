#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../template/template.hpp"
#include"../../Graph/doubling_lowest_common_ancestor.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  Doubling_LCA<int>g(n);
  for(int i=1;i<n;i++){
    int u;
    cin>>u;
    g.add_edge(u,i);
  }
  g.build();
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<g.lca(u,v)<<endl;
  }
}