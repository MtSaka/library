#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include"../../../template/template.hpp"
#include"../../../Graph/tree/doubling_lowest_common_ancestor.hpp"
int main(){
  int n;
  cin>>n;
  Doubling_LCA<int>g(n);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    while(k--){
      int j;
      cin>>j;
      g.add_edge(i,j);
    }
  }
  int q;
  cin>>q;
  g.build();
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<g.lca(a,b)<<endl;
  }
}