#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../../template/template.hpp"
#include"../../../data-structure/dynamic-segment-tree.hpp"
long long op(long long a,long long b){return a+b;}
long long e(){return 0;}
int main(){
  int n,q;cin>>n>>q;
  DynamicSegmentTree<long long,op,e>seg(n);
  vi a(n);cin>>a;
  for(int i=0;i<n;i++)seg.set(i,a[i]);
  while(q--){
    int t,l,r;cin>>t>>l>>r;
    if(t)cout<<seg.query(l,r)<<endl;
    else seg.set(l,seg[l]+r);
  }
}