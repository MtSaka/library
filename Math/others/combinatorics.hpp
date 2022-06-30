#pragma once
#include"../modular/modint.hpp"
template<long long m>
struct combination{
  using mint=modint<m>;
  private:
  static vector<mint>dat,idat;
  inline static void extend(int sz){
    if((int)dat.size()<sz+1){
      int pre_sz=dat.size();
      dat.resize(sz+1,1);
      idat.resize(sz+1,1);
      for(int i=pre_sz;i<=sz;i++)dat[i]=dat[i-1]*i;
      idat[sz]/=dat[sz];
      for(int i=sz-1;i>=pre_sz;i--)idat[i]=idat[i+1]*(i+1);
    }
  }
  public:
  combination(int sz=0){if(dat.size()==0)dat={1},idat={1};extend(sz);}
  static inline mint fac(long long n){
    if(n<0)return mint(0);
    extend(n);
    return dat[n];
  }
  static inline mint finv(long long n){
    if(n<0)return mint(0);
    extend(n);
    return idat[n];
  }
  static mint com(long long n,long long k){
    if(k<0||n<k)return mint(0);
    return fac(n)*finv(k)*finv(n-k);
  }
  static mint hom(long long n,long long k){
    if(n<0||k<0)return mint(0);
    return k==0?1:com(n+k-1,k);
  }
  static mint per(long long n,long long k){
    if(k<0||n<k)return mint(0);
    return fac(n)*finv(n-k);
  }
};
template<long long m>
vector<modint<m>>combination<m>::dat=vector<modint<m>>();
template<long long m>
vector<modint<m>>combination<m>::idat=vector<modint<m>>();
template<long long p>
struct COMB{
  vector<vector<modint<p>>>comb;
  COMB(){
    comb.assign(p,vector<modint<p>>(p));
    comb[0][0]=1;
    for(int i=1;i<p;i++){
      comb[i][0]=1;
      for(int j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    }
  }
  modint<p>com(int n,int k){
    modint<p>ret=1;
    while(n>0||k>0){
      int ni=n%p,ki=k%p;
      ret*=comb[ni][ki];
      n/=p;k/=p;
    }
    return ret;
  }
};
/**
 * @brief Combinatorics(組み合わせ)
*/