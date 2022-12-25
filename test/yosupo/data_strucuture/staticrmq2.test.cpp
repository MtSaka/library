#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../../template/template.hpp"
#include"../../../data-structure/disjoint-sparse-table.hpp"
int op(int a,int b){return min(a,b);}
int e(){return INF<int>;}
int main(){
  INT(n,q);
  vi a(n);
  cin>>a;
  DisjointSparseTable<int,op,e>st(a);
  while(q--){
    INT(l,r);
    print(st.query(l,r));
  }
}