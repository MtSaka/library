#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include"../../../template/template.hpp"
#include"../../../ds/inversion.hpp"
int main(){
  INT(n);
  vi a(n);cin>>a;
  print(inversion(a));
}