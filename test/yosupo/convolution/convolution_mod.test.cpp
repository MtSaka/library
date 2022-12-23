#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include"../../../template/template.hpp"
#include"../../../math/convolution/ntt.hpp"
int main(){
  INT(n,m);
  vector<ModInt<998244353>>a(n),b(m);
  scan(a,b);
  NTT<998244353>ntt;
  print(ntt.multiply(a,b));
}