#pragma once
#include"../../template/template.hpp"
#include"fps.hpp"
#include"../others/combinatorics.hpp"

template<int m>
FormalPowerSeries<m>taylor_shift(FormalPowerSeries<m>f,modint<m>a){
  const int n=f.size();
  Combinatorics<m>c(n);
  for(int i=0;i<n;i++)f[i]*=c.fac(i);
  reverse(f.begin(),f.end());
  FormalPowerSeries<m>g(n,1);
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