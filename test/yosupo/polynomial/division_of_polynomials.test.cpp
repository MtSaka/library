// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/division_of_polynomials
#include"../../../template/template.hpp"
#include"../../../math/fps/fps.hpp"
using mint=ModInt<998244353>;
int main(){
  INT(n,m);
  FormalPowerSeries<mint>f(n),g(m);
  cin>>f>>g;
  auto [q,r]=f.div_mod(g);
  print(q.size(),r.size());
  print(q);
  print(r);  
}