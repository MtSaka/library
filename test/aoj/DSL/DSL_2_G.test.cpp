#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include"../../../template/template.hpp"
#include"../../../data-structure/lazy-segment-tree.hpp"
int main(){
  INT(n,q);
  RangeAddQueryRangeSumQuery<ll>RAQRSQ(n);
  while(q--){
    INT(t);
    if(t==0){
      INT(l,r,x);
      RAQRSQ.apply(l-1,r,x);
    }
    else{
      INT(l,r);
      print(RAQRSQ.prod(l-1,r));
    }
  }
}