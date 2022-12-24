#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include"../../../template/template.hpp"
#include"../../../math/fps/fps.hpp"
using mint=ModInt<998244353>;
int main(){
  int n;
  cin>>n;
  FormalPowerSeries<mint>fps(n);
  cin>>fps;
  print(fps.inv());
}