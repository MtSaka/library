#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../Math/fps.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  FPS<mod>f(n);
  cin>>f;
  cout<<f.pow(m)<<endl;
}