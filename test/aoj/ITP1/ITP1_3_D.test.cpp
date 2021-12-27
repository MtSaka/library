#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include"../../../template/template.hpp"
#include"../../../Math/factor.hpp"
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  for(auto &x:factor(c)){
    ans+=(a<=x&&x<=b);
  }
  print(ans);
}