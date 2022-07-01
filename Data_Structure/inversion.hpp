#pragma once
#include"BIT.hpp"
#include"../Others/compressor.hpp"
template<typename T>
long long inversion(vector<T>a)const{
  int n=a.size();
  compressor<T>c(a);
  c.build();
  a=c.pressed(a);
  long long ans=0;
  BIT<int>bit(c.size());
  for(int i=0;i<n;i++){
    ans+=i-bit.sum(a[i]+1);
    bit.add(a[i],1);
  }
  return ans;
}
/**
 * @brief Inversion Number(転倒数)
*/