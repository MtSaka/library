#include"com.hpp"
template<long long m>
modint<m> lagrange_polynominal(vector<modint<m>>&y,long long t){
  using mint=modint<m>;
  long long n=y.size()-1;
  combination<m>c(n);
  if(t<=n)return y[t];
  mint ret;
  vector<mint>dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);
  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);
  for(int i=0;i<=n;i++){
    mint tmp=y[i]*dp[i]*pd[i]*c.idat[i]*c.idat[n-i];
    if((n-i)&1)ret-=tmp;
    else ret+=tmp;
  }
  return ret;
}