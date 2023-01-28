#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include"../../../template/template.hpp"
#include"../../../string/rolling-hash.hpp"
int main(){
  RollingHash rh;
  STR(s);
  const int n=s.size();
  auto h=rh.get_hash(s);
  vi ans(n);
  rep(i,n)ans[i]=rh.lcp(h,h,0,n,i,n);
  print(ans);
}