#pragma once
#include"../../template/template.hpp"

template<typename T>
vector<T>lcm_convolution(vector<T>a,vector<T>b){
  const int n=a.size();
  vector<bool>sieve(n,true);
  for(int p=2;p<n;p++)if(sieve[p]){
    for(int i=1;i*p<n;i++)a[i*p]+=a[i],sieve[i*p]=false;
    sieve[p]=true;
  }
  for(int p=2;p<n;p++)if(sieve[p])for(int i=1;i*p<n;i++)b[i*p]+=b[i];
  for(int i=0;i<n;i++)a[i]*=b[i];
  for(int p=2;p<n;p++)if(sieve[p])for(int i=(n-1)/p;i>0;i--)a[i*p]-=a[i];
  return a;
}
/**
 * @brief LCM Convolution
*/