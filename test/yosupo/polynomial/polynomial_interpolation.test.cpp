#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include"../../../template/template.hpp"
#include"../../../math/fps/fps.hpp"
#include"../../../math/fps/polynomial-interpolation.hpp"
using mint=ModInt<998244353>;
int main(){
  INT(n);
  vector<mint>xs(n),ys(n);
  cin>>xs>>ys;
  print(polynomial_interpolation(xs,ys));
}