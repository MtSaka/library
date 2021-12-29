#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include"../../../template/template.hpp"
#include"../../../Graph/lowest_common_ancestor.hpp"
int main(){
  int n;
  cin>>n;
  Graph<int>g(n);
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
  if(n==1){
    while(q--)cout<<0<<endl;
    return 0;
  }
  LCA<int>lca(g);
  while(q--){
    int a,b;
    cin>>a>>b;
    cout<<lca.query(a,b)<<endl;
  }
}