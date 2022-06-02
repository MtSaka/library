#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../template/template.hpp"
#include"../../Data_Structure/sparse_table.hpp"
int op(int a,int b){return min(a,b);}
int main(){
  int n,q;
  cin>>n>>q;
  vector<int>a(n);
  cin>>a;
  sparse_table<int,op>st(a);
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<st.query(l,r)<<endl;
  }
}