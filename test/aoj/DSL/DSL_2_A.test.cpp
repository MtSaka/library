#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/segtree.hpp"
int op(int a,int b){return min(a,b);}
int e(){return INT_MAX;}
int main(){
  INT(n,q);
  segtree<int,op,e>s(n);
  while(q--){
    INT(t,x,y);
    if(t==0)s.set(x,y);
    else cout<<s.query(x,y+1)<<endl;
  }
}