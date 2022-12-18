#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../math/fps/fps.hpp"
int main(){
  long long n,m;
  cin>>n>>m;
  FPS<998244353>f(n);
  cin>>f;
  cout<<f.pow(m)<<endl;
}