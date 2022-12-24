#pragma once
#include"../../template/template.hpp"
#include"fps.hpp"

template<typename T,enable_if_t<is_modint<T>::value>* =nullptr>
FormalPowerSeries<T>subset_sum(vector<T>&count){
  const int n=(int)count.size();
  const int mod=T::get_mod();
  vector<T>inv_table(n);
  inv_table[1]=1;
  for(int i=2;i<n;i++)inv_table[i]=-inv_table[mod%i]*(mod/i);
  FormalPowerSeries<T>f(n);
  for(int i=1;i<n;i++)if(count[i].get()){
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