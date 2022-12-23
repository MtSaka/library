#define PROBLEM "https://judge.yosupo.jp/problem/TwoSat"
#include"../../../template/template.hpp"
#include"../../../graph/others/two-sat.hpp"
int main(){
  string s;
  int n,m;
  cin>>s>>s>>n>>m;
  TwoSat ts(n);
  while(m--){
    int a,b;
    cin>>a>>b>>s;
    ts.add_clause(abs(a)-1,a>0,abs(b)-1,b>0);
  }
  auto ans=ts.calc();
  if(ans.empty())fin("s UNSATISFIABLE");
  print("s SATISFIABLE");
  cout<<"v ";
  rep(i,n)cout<<(ans[i]?i+1:-i-1)<<" ";
  cout<<0<<endl;
}