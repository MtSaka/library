#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../template/template.cpp"
#include"../../Graph/lowest-common-ancestor.cpp"
int main(){
  MtSaka;
  INT(n,q);
  vector<vector<int>>g(n);
  rep(i,1,n){
    INT(a);
    g[i].push_back(a);
    g[a].push_back(i);
  }
  LCA lca(g);
  while(q--){
    INT(u,v);
    print(lca.query(u,v));
  }
}