#pragma once
#include"fps.hpp"
template<long long Mod>
vector<modint<Mod>>multipoint_evaluation(const FPS<Mod>&f,const vector<modint<Mod>>&xs){
  const int m=xs.size();
  int sz=1;
  while(sz<m)sz<<=1;
  vector<FPS<Mod>>g(sz+sz,{1});
  for(int i=0;i<m;i++)g[i+sz]={-xs[i],1};
  for(int i=sz;i-->1;)g[i]=g[i<<1]*g[i<<1|1];
  g[1]=f%g[1];
  for(int i=2;i<sz+m;i++)g[i]=g[i>>1]%g[i];
  vector<modint<Mod>>res(m);
  for(int i=0;i<m;i++)res[i]=(g[i+sz].empty()?modint<Mod>(0):g[i+sz][0]);
  return res;
}
/**
 * @brief Multipoint Evaluation(多点評価)
*/