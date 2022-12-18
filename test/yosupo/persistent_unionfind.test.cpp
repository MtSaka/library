#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include"../../template/template.hpp"
#include"../../data-structure/persistent-union-find.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  using node=PersistentUnionFind::node;
  PersistentUnionFind d(n);
  vector<node*>g(q+1);
  g[0]=d.get_root();
  for(int i=1;i<=q;i++){
    int t,k,u,v;
    cin>>t>>k>>u>>v;
    k++;
    if(t==0){
      g[i]=d.merge(u,v,g[k]).second;
    }
    else{
      cout<<d.same(u,v,g[k])<<endl;
    }
  }
}