#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"../../../template/template.hpp"
#include"../../../data-structure/binary-indexed-tree.hpp"
int main(){
  INT(n,q);
  BinaryIndexedTree<ll>bit(n);
  for(int i=0;i<n;i++){
    INT(a);
    bit.add(i,a);
  }
  while(q--){
    INT(t,l,r);
    if(t)print(bit.sum(l,r));
    else bit.add(l,r);
  }
}