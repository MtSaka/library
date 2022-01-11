#include"ntt.hpp"
vector<long long>convolution(const vector<long long>&a,const vector<long long>&b){
  const int n=a.size(),m=b.size();
  if(!n||!m)return {};
  static constexpr unsigned long long MOD1=754974721ull,MOD2=167772161ull,MOD3=469762049ull,M2M3=78812994116517889ull,M1M3=354658471880163329ull,M1M2=126663740442542081ull,M1M2M3=560135205046714369ull,i1=190329765ull,i2=58587104,i3=187290749ull;
  auto c1=NTT<MOD1>::multiply(a,b);
  auto c2=NTT<MOD2>::multiply(a,b);
  auto c3=NTT<MOD3>::multiply(a,b);
  vector<long long>c(n+m-1);
  static constexpr unsigned long long offset[5]={0,0,M1M2M3,2*M1M2M3,3*M1M2M3};
  for(int i=0;i<n+m-1;i++){
    unsigned long long x=0;
    x+=(c1[i]*i1)%MOD1*M2M3;
    x+=(c2[i]*i2)%MOD2*M1M3;
    x+=(c3[i]*i3)%MOD3*M1M2;
    long long diff=c1[i]-x%MOD1;
    if(diff<0)diff+=MOD1;
    x-=offset[diff%5];
    c[i]=x;
  }
  return c;
}
/**
 * @brief Convolution(畳み込み)
*/