#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include"../../template/template.hpp"
#include"../../math/fps/fps.hpp"
#include"../../math/fps/polynomial-interpolation.hpp"
using mint=modint<998244353>;
int main(){
  int n;
  cin>>n;
  vector<mint>xs(n),ys(n);
  cin>>xs>>ys;
  cout<<polynomial_interpolation(xs,ys)<<endl;
}