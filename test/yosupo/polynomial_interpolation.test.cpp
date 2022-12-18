#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include"../../template/template.hpp"
#include"../../math/fps/fps.hpp"
#include"../../math/fps/polynomial_interpolation.hpp"
using mint=modint<mod>;
int main(){
  int n;
  cin>>n;
  vector<mint>xs(n),ys(n);
  cin>>xs>>ys;
  cout<<polynominal_interpolation(xs,ys)<<endl;
}