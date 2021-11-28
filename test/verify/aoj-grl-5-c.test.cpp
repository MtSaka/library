#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include"../../template/template.cpp"
#include"../../Graph/lowest-common-ancestor.cpp"
int main(){
  INT(n);
  vector<vector<int>>g(n);
  rep(i,n){
    INT(k);
    rep(j,k){
      INT(a);
      g[i].push_back(a);
    }
  }
  INT(q);
  if(n==1){
    while(q--)print(0);
    return 0;
  }
  LCA lca(g);
  while(q--){
    INT(a,b);
    print(lca.query(a,b));
  }
}