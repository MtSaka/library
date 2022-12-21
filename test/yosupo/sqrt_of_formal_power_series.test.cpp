#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../math/fps/fps.hpp"
#include"../../math/modular/mod-sqrt.hpp"
using mint=ModInt<998244353>;
int main(){
  int n;
  cin>>n;
  FormalPowerSeries<998244353>f(n);
  cin>>f;
  auto get_sqrt=[&](mint x){return mint(mod_sqrt((ll)x.get(),998244353));};
  f=f.sqrt(-1,get_sqrt);
  if(f.empty())print(-1);
  else{
    print(f);
  }
}