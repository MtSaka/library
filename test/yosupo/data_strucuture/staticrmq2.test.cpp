#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../../template/template.hpp"
#include"../../../others/monoid.hpp"
#include"../../../ds/segment/disjoint-sparse-table.hpp"
int main(){
  INT(n,q);
  vi a(n);
  cin>>a;
  DisjointSparseTable<Monoid::Min<int>>st(a);
  while(q--){
    INT(l,r);
    print(st.prod(l,r));
  }
}