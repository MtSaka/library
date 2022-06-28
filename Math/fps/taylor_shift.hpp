#pragma once
#include"fps.hpp"
#include"../others/combinatorics.hpp"
template<long long Mod>
FPS<Mod>taylor_shift(FPS<Mod>f,modint<Mod>a,combination<Mod>&c){
  const int n=f.size();
  for(int i=0;i<n;i++)f[i]*=c.fac(i);
  reverse(f.begin(),f.end());
  FPS<Mod>g(n,1);
  for(int i=1;i<n;i++)g[i]=g[i-1]*a*c.fac(i-1)*c.finv(i);
  f*=g;
  f.resize(n);
  reverse(f.begin(),f.end());
  for(int i=0;i<n;i++)f[i]*=c.finv(i);
  return f;
}
/**
 * @brief Taylor Shift(多項式の平行移動)
*/