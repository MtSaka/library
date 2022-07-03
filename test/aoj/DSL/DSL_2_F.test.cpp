#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree_monoids.hpp"
int main(){
  int n,q;cin>>n>>q;
  RUQRMQ<int>seg(n);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      seg.apply(l,r+1,x);
    }
    else{
      int l,r;cin>>l>>r;
      int ret=seg.query(l,r+1);
      if(ret==INF<int>)ret=INT_MAX;
      cout<<ret<<endl;
    }
  }
}