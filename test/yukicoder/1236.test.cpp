// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1236
#include"../../template/template.hpp"
#include"../../math/others/rational.hpp"
int main(){
  STR(s,t);
  int a=stoi(s),b=stoi(t);
  Rational c(a*60+b),d(720,11),x(0);
  while(x<c)x+=d;
  x=x-c;
  print(x.num*60/x.den);
}