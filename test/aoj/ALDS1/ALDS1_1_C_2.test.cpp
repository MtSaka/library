#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include"../../../template/template.hpp"
#include"../../../math/number/prime_sieve.hpp"
int main(){
  int n;
  cin>>n;
  IsPrime<ll>ip(100000000);
  int ans=0;
  while(n--){
    int a;
    cin>>a;
    ans+=ip.is_prime(a);
  }
  print(ans);
}