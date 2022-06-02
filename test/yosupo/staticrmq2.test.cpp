#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../template/template.hpp"
#include"../../Data_Structure/disjoint_sparse_table.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  vi a(n);
  cin>>a;
  auto f=[](int a,int b){return min(a,b);};
  auto op=[](){return INF<int>;};
  disjoint_sparse_table<int,f,op>st(a);
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<st.query(l,r)<<endl;
  }
}