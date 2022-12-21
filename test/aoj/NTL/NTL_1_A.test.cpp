#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include"../../../template/template.hpp"
#include"../../../math/number/prime-factor.hpp"
int main(){
  int n;
  cin>>n;
  cout<<n<<":"<<prime_factor(n)<<endl;
}