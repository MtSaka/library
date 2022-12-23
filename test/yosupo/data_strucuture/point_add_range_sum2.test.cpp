#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../../template/template.hpp"
#include"../../../data-structure/binary-indexed-tree.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  BinaryIndexedTree<long long>bit(n);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    bit.add(i,a);
  }
  while(q--){
    int t,l,r;
    cin>>t>>l>>r;
    if(t)cout<<bit.query(l,r)<<endl;
    else bit.add(l,r);
  }
}