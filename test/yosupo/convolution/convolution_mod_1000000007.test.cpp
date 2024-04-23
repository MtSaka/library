// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/convolution_mod_1000000007
#include"../../../template/template.hpp"
#include"../../../math/convolution/convolution.hpp"
int main(){
  INT(n,m);
  vl a(n),b(m);
  scan(a,b);
  print(convolution<1000000007>(a,b));
}