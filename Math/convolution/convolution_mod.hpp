#include"ntt.hpp"
vector<long long>mod_convolution(const vector<long long>&a,const vector<long long>&b,const long long&m){
  static constexpr long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874;
  const long long m12_mod=78812994116517889%m;
  auto x=NTT<m1>::multiply(a,b);
  auto y=NTT<m2>::multiply(a,b);
  auto z=NTT<m3>::multiply(a,b);
  vector<long long>res(x.size());
  for(int i=0;i<(int)x.size();i++){
    long long v1=(y[i]-x[i])*m1_inv_m2%m2;
    if(v1<0)v1+=m2;
    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;
    if(v2<0)v2+=m3;
    long long c=(x[i]+m1*v1+m12_mod*v2)%m;
    if(c<0)c+=m;
    res[i]=c;
  }
  return res;
}
/**
 * @brief Arbitrary Mod Convolution(任意mod畳み込み)
*/