#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../template/template.hpp"
#include"../../Data_Structure/segtree.hpp"
long long op(long long a,long long b){return a+b;}
long long e(){return 0;}
int main(){
  int n,q;
  cin>>n>>q;
  vector<long long>a(n);
  cin>>a;
  segtree<long long,op,e>s(a);
  while(q--){
    int t,l,r;
    cin>>t>>l>>r;
    if(t)cout<<s.query(l,r)<<endl;
    else s.set(l,s[l]+r);
  }
}