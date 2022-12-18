#pragma once
#include"../../template/template.hpp"

long long phi(long long n){
  long long ans=n;
  for(long long i=2;i*i<=n;i++){
    if(n%i==0){
      ans/=i;ans*=i-1;
      while(n%i==0)n/=i;
    }
  }
  if(n>1)ans/=n,ans*=(n-1);
  return ans;
}
/**
 * @brief Euler's Totient Function(オイラーのφ関数)
*/