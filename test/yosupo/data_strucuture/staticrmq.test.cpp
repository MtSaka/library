#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include"../../../template/template.hpp"
#include"../../../data-structure/sparse-table.hpp"
int main(){
  int n,q;
  cin>>n>>q;
  vector<int>a(n);
  cin>>a;
  auto st=MakeSparseTable(a,[](int a,int b){return min(a,b);});
  while(q--){
    int l,r;
    cin>>l>>r;
    cout<<st.query(l,r)<<endl;
  }
}