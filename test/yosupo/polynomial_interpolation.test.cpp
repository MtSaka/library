#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include"../../template/template.hpp"
#include"../../Math/fps/fps.hpp"
#include"../../Math/fps/polynomial_interpolation.hpp"
using mint=modint<mod>;
int main(){
  int n;
  cin>>n;
  vector<mint>xs(n),ys(n);
  cin>>xs>>ys;
  cout<<polynominal_interpolation(xs,ys)<<endl;
}