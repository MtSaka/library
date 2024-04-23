// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
#include"../../../template/template.hpp"
#include"../../../ds/segment/segment-tree.hpp"
int main(){
  INT(n,q);
  vl a(n);cin>>a;
  RangeSumQuery<ll>RSQ(a);
  while(q--){
    int t,l,r;
    cin>>t>>l>>r;
    if(t==0)RSQ.apply(l,r);
    else print(RSQ.prod(l,r));
  }
}