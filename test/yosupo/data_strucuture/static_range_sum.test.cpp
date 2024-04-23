// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_sum
#include"../../../template/template.hpp"
#include"../../../others/monoid.hpp"
#include"../../../ds/segment/disjoint-sparse-table.hpp"
int main(){
  INT(n,q);
  vl a(n);
  cin>>a;
  DisjointSparseTable<Monoid::Sum<ll>>st(a);
  while(q--){
    INT(l,r);
    print(st.prod(l,r));
  }
}