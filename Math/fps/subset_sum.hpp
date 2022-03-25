#pragma once
#include"fps.hpp"
template<long long Mod>
FPS<Mod>subset_sum(vector<modint<Mod>>&count){
  const int n=(int)count.size();
  vector<modint<Mod>>inv_table(n);
  inv_table[1]=1;
  for(int i=2;i<n;i++)inv_table[i]=-inv_table[mod%i]*(mod/i);
  FPS<Mod>f(n);
  for(int i=1;i<n;i++)if(count[i].x){
    for(int j=1,k=i;k<n;j++,k+=i){
      if(j&1)f[k]+=inv_table[j]*count[i];
      else f[k]-=inv_table[j]*count[i];
    }
  }
  return f.exp();
}