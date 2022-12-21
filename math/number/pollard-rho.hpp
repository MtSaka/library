#pragma once
#include"../../template/template.hpp"
#include"../../others/random.hpp"
#include"../modular/montgomery-modint.hpp"
#include"miller-rabin.hpp"
#include"../../string/run-length.hpp"

template<typename T,typename Rand>
ull pollard_rho(ull n,Rand&rand){
  if(~n&1)return 2;
  if(T::get_mod()!=n)T::set_mod(n);
  T c,e=1;
  auto f=[&](T x)->T {return x*x+c;};
  constexpr int m=128;
  while(1){
    c=rand.uniform(1ull,n-1);
    T x=rand.uniform(2ull,n-1),y=x;
    ull g=1;
    while(g==1){
      T p=e,tx=x,ty=y;
      rep(i,m){
        x=f(x);
        y=f(f(y));
        p*=x-y;
      }
      g=gcd(p.get(),n);
      if(g==1)continue;
      rep(i,m){
        tx=f(tx);
        ty=f(f(ty));
        g=gcd((tx-ty).get(),n);
        if(g!=1){
          if(g!=n)return g;
          break;
        }
      }
    }
  }
  return -1;
}
template<typename T=MontgomeryModInt<ull,-3>,typename Rand=Random64>
vector<ull>factorize(ull n,Rand&rand=rand64){
  if(n==1)return {};
  vector<ull>res;
  vector<ull>st={n};
  while(!st.empty()){
    ull t=st.back();
    st.pop_back();
    if(t==1)continue;
    if(is_prime_fast(t)){
      res.push_back(t);
      continue;
    }
    ull p=pollard_rho<T>(t,rand);
    st.push_back(p);
    st.push_back(t/p);
  }
  sort(all(res));
  return res;
}
template<typename T=MontgomeryModInt<ull,-3>,typename Rand=Random64>
vector<pair<ull,int>>expfactorize(ull n,Rand&rand=rand64){
  auto res=factorize<T>(n,rand);
  return run_length(res);
}
/**
 * @brief Pollard's Rho Factorization(ポラード・ロー法)
*/