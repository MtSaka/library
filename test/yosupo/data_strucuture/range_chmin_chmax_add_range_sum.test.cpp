// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
#include"../../../template/template.hpp"
#include"../../../ds/segment/segment-tree-beats.hpp"
int main(){
  int n,q;cin>>n>>q;
  vl a(n);cin>>a;
  SegmentTreeBeats<ll>seg(a);
  while(q--){
    int t;cin>>t;
    if(t==0){
      int l,r;ll x;
      cin>>l>>r>>x;
      seg.range_chmin(l,r,x);
    }
    else if(t==1){
      int l,r;ll x;
      cin>>l>>r>>x;
      seg.range_chmax(l,r,x);
    }
    else if(t==2){
      int l,r;ll x;
      cin>>l>>r>>x;
      seg.range_add(l,r,x);
    }
    else{
      int l,r;cin>>l>>r;
      print(seg.range_sum(l,r));
    }
  }
}