#pragma once
#include"../../template/template.hpp"
#include"../modular/montgomery-modint.hpp"

template<typename T>
constexpr bool miller_rabin(ull n,const ull base[],int sz){
  if(T::get_mod()!=n)T::set_mod(n);
  ull d=n-1;
  while(~d&1)d>>=1;
  const T e1=1,e2=n-1;
  rep(i,sz){
    ull a=base[i];
    if(n<=a)return true;
    ull t=d;
    T y=T(a).pow(t);
    while(t!=n-1&&y!=e1&&y!=e2){
      y*=y;
      t<<=1;
    }
    if(y!=e2&&(~t&1))return false;
  }
  return true;
}
constexpr bool is_prime_fast(ull n){
  constexpr ull base_int[3]={2,7,61},base_ll[7]={2,325,9375,28178,450775,9780504,1795265022};
  if(n==2)return true;
  if(n<2||n%2==0)return false;
  if(n<(1u<<31))return miller_rabin<MontgomeryModInt<unsigned int,-2>>(n,base_int,3);
  return miller_rabin<MontgomeryModInt<ull,-2>>(n,base_ll,7);
}
template<ull n>constexpr bool is_prime_v=is_prime_fast(n);
/**
 * @brief Miller-Rabin Primality Test(ミラーラビン素数判定)
*/