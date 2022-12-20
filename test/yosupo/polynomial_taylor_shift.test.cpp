#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include"../../template/template.hpp"
#include"../../math/fps/taylor-shift.hpp"
using mint=ModInt<998244353>;
int main(){
  int n,c;
  cin>>n>>c;
  FormalPowerSeries<998244353>f(n);
  cin>>f;
  print(taylor_shift(f,mint(c)));
}