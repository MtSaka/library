// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
#include"../../../template/template.hpp"
#include"../../../ds/segment/segment-tree.hpp"
int main(){
  INT(n,q);
  RangeMinimumQuery<int,(1ull<<31)-1>RMQ(n);
  while(q--){
    INT(t,x,y);
    if(t==0)RMQ.set(x,y);
    else print(RMQ.prod(x,y+1));
  }
}