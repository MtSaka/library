#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include"../../../template/template.hpp"
#include"../../../Math/modpow.hpp"
int main(){
  long long m,n;
  cin>>m>>n;
  print(modpow(m,n,(long long)MOD));
}