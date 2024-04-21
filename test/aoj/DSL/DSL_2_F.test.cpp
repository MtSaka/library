#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F"
#include"../../../template/template.hpp"
#include"../../../ds/segment/lazy-segment-tree.hpp"
int main(){
  INT(n,q);
  RangeUpdateQueryRangeMinimumQuery<int,(1u<<31)-1>RUQRMQ(n);
  while(q--){
    INT(t);
    if(t==0){
      INT(l,r,x);
      RUQRMQ.apply(l,r+1,x);
    }
    else{
      INT(l,r);
      print(RUQRMQ.prod(l,r+1));
    }
  }
}