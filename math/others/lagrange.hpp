#pragma once
#include"../../template/template.hpp"
#include"combinatorics.hpp"

template<long long m>
modint<m>lagrange_polynomial(const vector<modint<m>>&y,const long long&t){
  using mint=modint<m>;
  const int n=y.size()-1;
  Combinatorics<m>c(n);
  if(t<=n)return y[t];
  mint ret;
  vector<mint>dp(n+1,1),pd(n+1,1);
  for(int i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);
  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);
  for(int i=0;i<=n;i++){
    mint tmp=y[i]*dp[i]*pd[i]*c.finv(i)*c.finv(n-i);
    if((n-i)&1)ret-=tmp;
    else ret+=tmp;
  }
  return ret;
}
/**
 * @brief Lagrange Polynomial(多項式補間)
*/