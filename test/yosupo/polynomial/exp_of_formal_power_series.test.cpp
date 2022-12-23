#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include"../../../template/template.hpp"
#include"../../../math/fps/fps.hpp"
int main(){
  int n;
  cin>>n;
  FormalPowerSeries<998244353>f(n);
  cin>>f;
  cout<<f.exp()<<endl;
}