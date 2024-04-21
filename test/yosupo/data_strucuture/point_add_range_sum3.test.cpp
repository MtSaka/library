#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../../template/template.hpp"
#include"../../../ds/segment/dynamic-segment-tree.hpp"
long long op(long long a,long long b){return a+b;}
long long e(){return 0;}
int main(){
  INT(n,q);
  DynamicSegmentTree<long long,op,e>seg(n);
  vi a(n);cin>>a;
  rep(i,n)seg.set(i,a[i]);
  while(q--){
    INT(t,l,r);
    if(t)print(seg.query(l,r));
    else seg.set(l,seg[l]+r);
  }
}