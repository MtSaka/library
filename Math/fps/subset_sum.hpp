#pragma once
#include"fps.hpp"
template<int m>
FPS<m>subset_sum(vector<modint<m>>&count){
  const int n=(int)count.size();
  vector<modint<m>>inv_table(n);
  inv_table[1]=1;
  for(int i=2;i<n;i++)inv_table[i]=-inv_table[mod%i]*(mod/i);
  FPS<m>f(n);
  for(int i=1;i<n;i++)if(count[i].val()){
    for(int j=1,k=i;k<n;j++,k+=i){
      if(j&1)f[k]+=inv_table[j]*count[i];
      else f[k]-=inv_table[j]*count[i];
    }
  }
  return f.exp();
}
/**
 * @brief Count Subset Sum
*/