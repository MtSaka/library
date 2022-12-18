#pragma once
#include"../../template/template.hpp"
#include"fast-prime.hpp"
#include"../modular/modpow.hpp"

int primitive_root(int n){
  if(n==2)return 1;
  if(n==167772161)return 3;
  if(n==469762049)return 3;
  if(n==754974721)return 11;
  if(n==998244353)return 3;
  if(n==1224736769)return 3;
  auto divs=fastprime::factorize(n-1);
  divs.erase(unique(divs.begin(),divs.end()),divs.end());
  for(int g=2;;g++){
    bool ok=true;
    for(int d:divs){
      if(modpow(g,(n-1)/d,n)==1){
        ok=false;
        break;
      }
    }
    if(ok)return g;
  }
}
/**
 * @brief Primitive Root(原始根)
*/