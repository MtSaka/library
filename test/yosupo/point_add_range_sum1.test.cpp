#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../template/template.hpp"
#include"../../Data_Structure/segtree_monoids.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  vector<long long>a(n);
  cin>>a;
  RSQ<long long>s(a);
  while(q--){
    int t,l,r;
    cin>>t>>l>>r;
    if(t)cout<<s.query(l,r)<<endl;
    else s.set(l,s[l]+r);
  }
}