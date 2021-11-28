#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include"../../template/template.cpp"
#include"../../Math/ntt.cpp"
int main(){
  INT(n,m);
  vector<modint<mod>>a(n),b(m);
  scan(a,b);
  NTT<mod>ntt;
  print(ntt.multiply(a,b));
}