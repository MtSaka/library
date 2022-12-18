#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"
#include"../../../template/template.hpp"
#include"../../../data-structure/segment-tree-monoids.hpp"
int main(){
  int n,q;cin>>n>>q;
  RUQRSQ<int>seg(n);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l,r+1,x);
    }
    else{
      int l,r;cin>>l>>r;
      cout<<seg.query(l,r+1)<<endl;
    }
  }
}