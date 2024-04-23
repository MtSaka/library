// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/exp_of_formal_power_series
#include"../../../template/template.hpp"
#include"../../../math/fps/fps.hpp"
using mint=ModInt<998244353>;
int main(){
  INT(n);
  FormalPowerSeries<mint>f(n);
  cin>>f;
  print(f.exp());
}