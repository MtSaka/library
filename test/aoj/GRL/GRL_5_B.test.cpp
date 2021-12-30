#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"
#include"../../../template/template.hpp"
#include"../../../Graph/rerooting.hpp"
long long f(long long a,long long b){
  return max(a,b);
}
long long g(long long a,ReRooting<long long>::Edge b){
  return a+b.cost;
}
int main(){
  int n;
  cin>>n;
  ReRooting<long long>r(n,f,g);
  for(int i=0;i<n-1;i++){
    int s,t;
    long long w;
    cin>>s>>t>>w;
    r.add_edge(s,t,w);
  }
  auto ans=r.solve();
  for(auto i:ans)cout<<i<<endl;
}