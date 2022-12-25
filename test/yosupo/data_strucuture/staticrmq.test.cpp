#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../../template/template.hpp"
#include"../../../others/monoid.hpp"
#include"../../../data-structure/sparse-table.hpp"
int main(){
  INT(n,q);
  vi a(n);cin>>a;
  SparseTable<Monoid::Min<int>>st(a);
  while(q--){
    INT(l,r);
    print(st.prod(l,r));
  }
}