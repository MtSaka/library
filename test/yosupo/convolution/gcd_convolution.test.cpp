// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/gcd_convolution
#include"../../../template/template.hpp"
#include"../../../math/modular/modint.hpp"
#include"../../../math/convolution/gcd-convolution.hpp"
using mint=ModInt<998244353>;
int main(){
  INT(n);
  vector<mint>a(n+1),b(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
  auto ans=gcd_convolution(a,b);
  ans.erase(ans.begin());
  print(ans);
}