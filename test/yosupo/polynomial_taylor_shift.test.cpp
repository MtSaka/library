#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include"../../template/template.hpp"
#include"../../math/fps/taylor_shift.hpp"
using mint=modint<mod>;
int main(){
  int n,c;
  cin>>n>>c;
  FPS<mod>f(n);
  cin>>f;
  print(taylor_shift(f,mint(c)));
}