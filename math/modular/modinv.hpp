#pragma once
#include"../../template/template.hpp"

template<typename T>
T modinv(T a,T m){
  T b=m,c=1,d=0,t;
  while(b){
    t=a/b;
    a-=t*b;swap(a,b);
    c-=t*d;swap(c,d);
  }
  c%=m;
  if(c<0)c+=m;
  return c;
}
/**
 * @brief Mod Inv(逆元)
*/