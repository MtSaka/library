#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include"../../../template/template.hpp"
#include"../../../math/convolution/mod-convolution.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  vector<long long>a(n),b(m);
  scan(a,b);
  print(mod_convolution(a,b,1000000007));
}