#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"
#include"../../../template/template.hpp"
#include"../../../math/fps/fps.hpp"
#include"../../../math/modular/mod-sqrt.hpp"
using mint=ModInt<998244353>;
int main(){
  int n;
  cin>>n;
  FormalPowerSeries<mint>f(n);
  cin>>f;
  auto get_sqrt=[&](mint x)->mint {return mint(mod_sqrt((ll)x.get(),998244353));};
  f=f.sqrt(get_sqrt,-1);
  if(f.empty())print(-1);
  else{
    print(f);
  }
}