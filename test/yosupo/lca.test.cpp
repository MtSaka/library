#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../template/template.hpp"
#include"../../Graph/lowest_common_ancestor.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  Graph<int>g(n);
  for(int i=0;i<n-1;i++){
    int u;
    cin>>u;
    g.add_edge(u,i);
  }
  LCA<int>lca(g);
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<lca.query(u,v)<<endl;
  }
}