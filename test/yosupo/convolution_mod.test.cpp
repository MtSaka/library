#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include"../../template/template.hpp"
#include"../../math/convolution/ntt.hpp"
int main(){
  INT(n,m);
  vector<modint<mod>>a(n),b(m);
  scan(a,b);
  NTT<mod>ntt;
  print(ntt.multiply(a,b));
}