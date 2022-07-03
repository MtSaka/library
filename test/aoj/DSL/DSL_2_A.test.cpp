#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree_monoids.hpp"
int main(){
  INT(n,q);
  RmQ<int>s(vector<int>(n,INT_MAX));
  while(q--){
    INT(t,x,y);
    if(t==0)s.set(x,y);
    else{
      cout<<s.query(x,y+1)<<endl;
    }
  }
}