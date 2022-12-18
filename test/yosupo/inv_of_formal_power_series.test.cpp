#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../math/fps/fps.hpp"
int main(){
  int n;
  cin>>n;
  FPS<998244353>fps(n);
  cin>>fps;
  print(fps.inv());
}