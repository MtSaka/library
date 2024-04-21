#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include"../../../template/template.hpp"
#include"../../../ds/union-find/rollback-union-find.hpp"
int main(){
  int n,q;cin>>n>>q;
  vector<vector<array<int,3>>>g(q+1);
  vector<vector<array<int,3>>>a(q+1);
  rep(i,q){
    int t,k,u,v;cin>>t>>k>>u>>v;
    if(t==0)g[k+1].eb(array<int,3>{(int)i+1,u,v});
    else a[k+1].eb(array<int,3>{(int)i,u,v});
  }
  vector<int>ans(q,-1);
  RollbackUnionFind dsu(n);
  REC([&](auto&&f,int v)->void{
    for(auto&b:a[v])ans[b[0]]=dsu.same(b[1],b[2]);
    for(auto&e:g[v]){
      dsu.merge(e[1],e[2]);
      f(e[0]);
      dsu.undo();
    }
  })(0);
  for(auto&i:ans)if(i!=-1)print(i);
}
