#pragma once
#include"modpow.hpp"
template<typename T,typename S>
S mod_sqrt(T a,S p){
  a%=p;
  if(a==0)return 0;
  if(p==2)return a;
  if(modpow(a,(p-1)/2,p)!=1)return -1;
  if((p&3)==3)return modpow(a,(p+1)/4,p);
  S q=p-1,s=0,z=2;
  while(!(q&1))q>>=1,s++;
  while(modpow(z,(p-1)/2,p)==1)z++;
  S m=s,c=modpow(z,q,p),t=modpow(a,q,p),r=modpow(a,(q+1)/2,p);
  while(t!=1){
    S pow_t=t*t%p,m_update=0;
    for(int j=1;j<m;j++){
      if(pow_t==1){
        m_update=j;
        break;
      }
      pow_t=pow_t*pow_t%p;
    }
    S b=modpow(c,S(1)<<(m-m_update-1),p);
    m=m_update,c=modpow(b,2,p),t=(t*b%p)*b%p,r=r*b%p;
  }
  return r;
}
/**
 * @brief Mod Square Root(平方剰余)
*/