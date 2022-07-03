#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree_monoids.hpp"
int main(){
  int n,q;cin>>n>>q;
  RUQ<int>seg(n,int((1LL<<31)-1));
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l,r+1,x);
    }
    else{
      int k;cin>>k;
      print(seg[k]);
    }
  }
}