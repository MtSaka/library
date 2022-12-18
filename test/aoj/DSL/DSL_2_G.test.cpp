#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include"../../../template/template.hpp"
#include"../../../data-structure/segment-tree-monoids.hpp"
int main(){
  int n,q;cin>>n>>q;
  RAQRSQ<ll>seg(n);
  while(q--){
    INT(t);
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l-1,r,x);
    }
    else{
      int l,r;cin>>l>>r;
      cout<<seg.query(l-1,r)<<endl;
    }
  }
}