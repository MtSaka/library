#pragma once
#include"fps.hpp"
#include"../others/combinatorics.hpp"
template<long long m>
FPS<m>TaylorShift(FPS<m>f,modint<m>a,combination<m>&c){
  const int n=f.size();
  for(int i=0;i<n;i++)f[i]*=c.fac(i);
  reverse(f.begin(),f.end());
  FPS<m>g(n,1);
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