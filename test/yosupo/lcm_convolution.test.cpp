#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include"../../template/template.hpp"
#include"../../math/modular/modint.hpp"
#include"../../math/convolution/lcm-convolution.hpp"
using mint=modint<998244353>;
int main(){
  int n;cin>>n;
  vector<mint>a(n+1),b(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
  auto ans=lcm_convolution(a,b);
  for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
}