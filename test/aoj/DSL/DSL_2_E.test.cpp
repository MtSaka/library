#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree_monoids.hpp"
int main(){
  int n,q;cin>>n>>q;
  RAQ<int>seg(n,0);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l-1,r,x);
    }
    else{
      int k;cin>>k;
      print(seg[k-1]);
    }
  }
}