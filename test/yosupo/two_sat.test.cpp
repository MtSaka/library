#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include"../../template/template.hpp"
#include"../../Graph/others/two_sat.hpp"
int main(){
  string s;
  int n,m;
  cin>>s>>s>>n>>m;
  two_sat ts(n);
  while(m--){
    int a,b;
    cin>>a>>b>>s;
    ts.add_clause(abs(a)-1,a>0,abs(b)-1,b>0);
  }
  auto ans=ts.calc();
  if(ans.empty())fin("s UNSATISFIABLE");
  print("S SATISFIABLE");
  cout<<"v ";
  rep(i,n)cout<<(ans[i]?i+1:-i-1)<<" ";
  cout<<0<<endl;
}