#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../template/template.hpp"
#include"../../data-structure/disjoint-sparse-table.hpp"
int op(int a,int b){return min(a,b);}
int e(){return INF<int>;}
int main(){
  int n,q;
  cin>>n>>q;
  vi a(n);
  cin>>a;
  DisjointSparseTable<int,op,e>st(a);
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<st.query(l,r)<<endl;
  }
}