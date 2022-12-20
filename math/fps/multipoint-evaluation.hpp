#pragma once
#include"../../template/template.hpp"
#include"fps.hpp"

template<int m>
vector<ModInt<m>>multipoint_evaluation(const FormalPowerSeries<m>&f,const vector<ModInt<m>>&xs){
  const int n=xs.size();
  int sz=1;
  while(sz<n)sz<<=1;
  vector<FormalPowerSeries<m>>g(sz+sz,{1});
  for(int i=0;i<n;i++)g[i+sz]={-xs[i],1};
  for(int i=sz;i-->1;)g[i]=g[i<<1]*g[i<<1|1];
  g[1]=f%g[1];
  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%g[i];
  vector<ModInt<m>>res(n);
  for(int i=0;i<n;i++)res[i]=(g[i+sz].empty()?ModInt<m>():g[i+sz][0]);
  return res;
}
/**
 * @brief Multipoint Evaluation(多点評価)
*/