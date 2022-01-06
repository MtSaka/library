#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../Math/fps.hpp"
int main(){
  int n;
  cin>>n;
  FPS<mod>f(n);
  cin>>f;
  cout<<f.exp()<<endl;
}