#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include"../../template/template.hpp"
#include"../../Math/fps/taylor_shift.hpp"
using mint=modint<mod>;
combination<mod>a(525000);
int main(){
  int n,c;
  cin>>n>>c;
  FPS<mod>f(n);
  cin>>f;
  print(TaylorShift(f,mint(c),a));
}