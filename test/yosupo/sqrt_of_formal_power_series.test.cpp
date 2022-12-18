#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../math/fps/fps.hpp"
#include"../../math/modular/mod_sqrt.hpp"
using mint=modint<mod>;
int main(){
  int n;
  cin>>n;
  FPS<mod>f(n);
  cin>>f;
  auto get_sqrt=[&](mint x){return mint(mod_sqrt((ll)x.val(),mod));};
  f=f.sqrt(-1,get_sqrt);
  if(f.empty())print(-1);
  else{
    print(f);
  }
}