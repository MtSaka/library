#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree_monoids.hpp"
int main(){
  INT(n,q);
  RmQ<int>s(n);
  while(q--){
    INT(t,x,y);
    if(t==0)s.set(x,y);
    else{
      int ret=s.query(x,y+1);
      cout<<(ret==INF<int>?INT_MAX:ret)<<endl;
    }
  }
}