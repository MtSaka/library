#pragma once
#include"fps.hpp"
template<long long Mod>
FPS<Mod>polynominal_interpolation(const vector<modint<Mod>>&xs,const vector<modint<Mod>>&ys){
  const int n=xs.size();
  int sz=1;
  while(sz<n)sz<<=1;
  vector<FPS<Mod>>mul(sz*2,{1});
  for(int i=0;i<n;i++)mul[i+sz]={-xs[i],modint<Mod>(1)};
  for(int i=sz;i-->1;)mul[i]=mul[i<<1]*mul[i<<1|1];
  vector<FPS<Mod>>g(2*sz);
  g[1]=mul[1].diff()%mul[1];
  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%mul[i];
  for(int i=0;i<n;i++)g[sz+i]={ys[i]/g[sz+i][0]};
  for(int i=sz;i-->1;)g[i]=g[i<<1]*mul[i<<1|1]+g[i<<1|1]*mul[i<<1];
  return g[1];
}
/**
 * @brief Polynomial Interpolation(多項式補間)
*/