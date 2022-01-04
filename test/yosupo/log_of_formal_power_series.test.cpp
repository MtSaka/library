#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../Math/fps.hpp"
int main(){
  int n;
  cin>>n;
  FPS<mod>fps(n);
  cin>>fps;
  print(fps.log());
}