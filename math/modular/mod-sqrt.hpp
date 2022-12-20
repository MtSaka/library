#pragma once
#include"../../template/template.hpp"

template<typename T,typename S>
S mod_sqrt(T a,const S&p){
  a%=p;
  if(a==0)return 0;
  if(p==2)return a;
  if(mod_pow(a,(p-1)/2,p)!=1)return -1;
  if((p&3)==3)return mod_pow(a,(p+1)/4,p);
  S q=p-1,s=0,z=2;
  while(!(q&1))q>>=1,s++;
  while(mod_pow(z,(p-1)/2,p)==1)z++;
  S m=s,c=mod_pow(z,q,p),t=mod_pow(a,q,p),r=mod_pow(a,(q+1)/2,p);
  while(t!=1){
    S pow_t=t*t%p,m_update=0;
    for(int j=1;j<m;j++){
      if(pow_t==1){
        m_update=j;
        break;
      }
      pow_t=pow_t*pow_t%p;
    }
    S b=mod_pow(c,S(1)<<(m-m_update-1),p);
    m=m_update,c=mod_pow(b,2,p),t=(t*b%p)*b%p,r=r*b%p;
  }
  return r;
}
/**
 * @brief Mod Square Root(平方剰余)
*/