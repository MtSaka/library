#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"
#include"../../../template/template.hpp"
#include"../../../data-structure/lazy-segment-tree.hpp"
int main(){
  INT(n,q);
  RangeAddQueryRangeMinimumQuery<int>RAQRMQ(n,0);
  while(q--){
    INT(t);
    if(t==0){
      INT(l,r,x);
      RAQRMQ.apply(l,r+1,x);
    }
    else{
      INT(l,r);
      print(RAQRMQ.prod(l,r+1));
    }
  }
}