#pragma once
#include"BIT.hpp"
template<typename T>
long long inversion(vector<T>a){
  int n=a.size();
  vector<T>b=a;
  sort(b.begin(),b.end());
  map<long long,int>mp;
  for(int i=0;i<n;i++)mp[b[i]]=i+1;
  for(int i=0;i<n;i++)a[i]=mp[a[i]];
  long long ans=0;
  BIT<int>c(n);
  for(int i=0;i<n;i++){
    ans+=i-c.sum(a[i]);
    c.add(a[i],1);
  }
  return ans;
}
/**
 * @brief Inversion Number(転倒数)
*/