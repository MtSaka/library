#pragma once
#include"../../template/template.hpp"
#include"../modular/modint.hpp"

template<int m>
struct Combinatorics{
  using mint=modint<m>;
  private:
  static vector<mint>dat,idat;
  inline static void extend(int sz){
    if((int)dat.size()<sz+1){
      int pre_sz=max<int>(1,dat.size());
      dat.resize(sz+1,1);
      idat.resize(sz+1,1);
      for(int i=pre_sz;i<=sz;i++)dat[i]=dat[i-1]*i;
      idat[sz]=1/dat[sz];
      for(int i=sz-1;i>=pre_sz;i--)idat[i]=idat[i+1]*(i+1);
    }
  }
  public:
  Combinatorics(int sz=0){extend(sz);}
  template<typename T>
  static inline mint fac(T n){
    if(n<0)return mint();
    extend(n);
    return dat[n];
  }
  template<typename T>
  static inline mint finv(T n){
    if(n<0)return mint();
    extend(n);
    return idat[n];
  }
  template<typename T,typename U>
  static mint com(T n,U k){
    if(k<0||n<k)return mint();
    return fac(n)*finv(k)*finv(n-k);
  }
  template<typename T,typename U>
  static mint hom(T n,U k){
    if(n<0||k<0)return mint();
    return k==0?1:com(n+k-1,k);
  }
  template<typename T,typename U>
  static mint per(T n,U k){
    if(k<0||n<k)return mint();
    return fac(n)*finv(n-k);
  }
};
template<int m>
vector<modint<m>>Combinatorics<m>::dat=vector<modint<m>>();
template<int m>
vector<modint<m>>Combinatorics<m>::idat=vector<modint<m>>();
template<long long p>
struct COMB{
  private:
  static vector<vector<modint<p>>>comb;
  static void init(){
    if(!comb.empty())return;
    comb.assign(p,vector<modint<p>>(p));
    comb[0][0]=1;
    for(int i=1;i<p;i++){
      comb[i][0]=1;
      for(int j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    }
  }
  public:
  COMB(){
    init();
  }
  modint<p>com(int n,int k){
    init();
    modint<p>ret=1;
    while(n>0||k>0){
      int ni=n%p,ki=k%p;
      ret*=comb[ni][ki];
      n/=p;k/=p;
    }
    return ret;
  }
};
template<long long p>
vector<vector<modint<p>>>COMB<p>::comb=vector<vector<modint<p>>>();
/**
 * @brief Combinatorics(組み合わせ)
*/