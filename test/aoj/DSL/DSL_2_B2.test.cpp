#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree_monoids.hpp"
int main(){
  INT(n,q);
  RSQ<int>seg(n);
  while(q--){
    INT(t,x,y);
    if(t)print(seg.query(x-1,y));
    else seg.set(x-1,seg[x-1]+y);
  }
}