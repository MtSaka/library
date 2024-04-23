// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
#include"../../../template/template.hpp"
int main(){
  INT(n);
  int g=1;
  while(n--){
    INT(a);
    g=g/gcd(g,a)*a;
  }
  print(g);
}