#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include"../../../template/template.hpp"
#include"../../../data-structure/dual-segment-tree.hpp"
int main(){
  INT(n,q);
  RangeUpdateQuery<int>RUQ(n,(1u<<31)-1);
  while(q--){
    INT(t);
    if(t==0){
      INT(l,r,x);
      RUQ.apply(l,r+1,x);
    }
    else{
      INT(k);
      print(RUQ[k]);
    }
  }
}