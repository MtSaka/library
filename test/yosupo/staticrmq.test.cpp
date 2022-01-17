#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../template/template.hpp"
#include"../../Data_Structure/sparse_table.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  vector<int>a(n);
  cin>>a;
  auto st=make_sparse_table(a,[](int a,int b){return min(a,b);});
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<st.query(l,r)<<endl;
  }
}