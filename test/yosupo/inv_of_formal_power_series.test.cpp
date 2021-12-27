#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include"../../template/template.hpp"
#include"../../Math/fps.hpp"
int main(){
  int n;
  cin>>n;
  vector<modint<mod>>a(n);
  cin>>a;
  FPS<mod>fps(a);
  fps.inv(n);
  print(fps.val);
}