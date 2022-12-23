#pragma once
#include"../../template/template.hpp"
#include"../modular/modint.hpp"
#include"../number/miller-rabin.hpp"
#include"../number/primitive-root.hpp"

template<unsigned int p,enable_if_t<is_prime_v<p>>* =nullptr>
struct NthRoot{
  private:
  static constexpr unsigned int lg=msb((p-1)&(1-p));
  array<unsigned int,lg+1>root,inv_root;
  public:
  constexpr NthRoot():root{},inv_root{}{
    root[lg]=mod_pow(constexpr_primitive_root<p>(),(p-1)>>lg,p);
    inv_root[lg]=mod_pow(root[lg],p-2,p);
    rrep(i,lg){
      root[i]=(ull)root[i+1]*root[i+1]%p;
      inv_root[i]=(ull)inv_root[i+1]*inv_root[i+1]%p;
    }
  }
  static constexpr unsigned int get_lg(){return lg;}
  constexpr unsigned int get(int n){return root[n];}
  constexpr unsigned int inv(int n){return inv_root[n];}
};
template<unsigned int p>constexpr NthRoot<p> nth_root;
template<typename T,enable_if_t<is_modint<T>::value>* =nullptr,enable_if_t<is_prime_v<T::get_mod()>>* =nullptr>
void ntt(vector<T>&a){
  const int sz=a.size();
  assert(sz<=((1-p)&(p-1)));
  assert((sz&(sz-1))==0);
  const int lg=msb(sz);
  rep(i,sz){
    const int j=reverse(i,lg);
    if(i<j)swap(a[i],a[j]);
  }
  rep(i,lg){
    const T w=nth_root<T::get_mod()>.get(i+1);
    rep(j,0,sz,1<<(i+1)){
      T z=1;
      rep(k,1<<i){
        T x=a[j+k],y=a[j+k+(1<<i)]*z;
        a[j+k]=x+y,a[j+k+(1<<i)]=x-y;
        z*=w;
      }
    }
  }
  rep(i,sz){
    const int j=reverse(i,lg);
    if(i<j)swap(a[i],a[j]);
  }
}
template<typename T,enable_if_t<is_modint<T>::value>* =nullptr,enable_if_t<is_prime_v<T::get_mod()>>* =nullptr>
void intt(vector<T>&a){
  const int sz=a.size();
  assert(sz<=((1-p)&(p-1)));
  assert((sz&(sz-1))==0);
  const int lg=msb(sz);
  rep(i,sz){
    const int j=reverse(i,lg);
    if(i<j)swap(a[i],a[j]);
  }
  rep(i,lg){
    const T w=nth_root<T::get_mod()>.inv(i+1);
    rep(j,0,sz,1<<(i+1)){
      T z=1;
      rep(k,1<<i){
        T x=a[j+k],y=a[j+k+(1<<i)]*z;
        a[j+k]=x+y,a[j+k+(1<<i)]=x-y;
        z*=w;
      }
    }
  }
  rep(i,sz){
    const int j=reverse(i,lg);
    if(i<j)swap(a[i],a[j]);
  }
  const T inv_sz=T(1)/sz;
  for(auto&x:a)x*=inv_sz;
}
template<typename T>
vector<T>convolution_naive(const vector<T>&a,const vector<T>&b){
  const int sz1=a.size(),sz2=b.size();
  vector<T>c(sz1+sz2-1);
  rep(i,sz1)rep(j,sz2)c[i+j]+=a[i]*b[j];
  return c;
}
//TODO:実装
template<typename T,enable_if_t<is_modint<T>::value>* =nullptr>
vector<T>convolution_for_any_mod(const vector<T>&a,const vector<T>&b){

}
template<typename T,enable_if_t<is_modint<T>::value>* =nullptr>
vector<T>convolution(vector<T>a,vector<T>b){

}
template<typename T,enable_if_t<is_integral<T>::value>* =nullptr,unsigned int p=998244353>
vector<T>convolution(const vector<T>&a,const vector<T>&b){
  const int sz1=a.size(),sz2=b.size()
  vector<ModInt<p>>a2(sz1),b2(sz2);
  rep(i,sz1)a2[i]=a[i];
  rep(i,sz2)b2[i]=b[i];
  auto c2=convolution(a2,b2);
  vector<T>c(sz1+sz2-1);
  rep(i,sz1+sz2-1)c[i]=c2[i].get();
  return c;
}
template<int m>
struct NTT{
  using mint=ModInt<m>;
  private:
  static ModInt<m> g;
  static int limit;
  static vector<ModInt<m>>root,inv_root;
  static void init(){
    if(!root.empty())return;
    g=primitive_root(m);
    long long now=m-1;
    while(!(now&1))now>>=1,limit++;
    root.resize(limit+1,1),inv_root.resize(limit+1,1);
    root[limit]=g.pow(now);
    inv_root[limit]/=root[limit];
    for(int i=limit-1;i>=0;i--){
      root[i]=root[i+1]*root[i+1];
      inv_root[i]=inv_root[i+1]*inv_root[i+1];
    }
  }
  public:
  NTT(){init();};
  static void dft(vector<mint>&a,int inv){
    init();
    const int sz=a.size();
    if(sz==1)return;
    const int mask=sz-1;
    vector<mint>b(sz);
    for(int i=sz>>1;i>=1;i>>=1){
      int e=__builtin_ffsll(sz/i)-1;
      mint w=1,z=(inv==1?root[e]:inv_root[e]);
      for(int j=0;j<sz;j+=i){
        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];
        w*=z;
      }
      swap(a,b);
    }
  }
  static vector<mint>multiply(vector<mint>a,vector<mint>b){
    int sz=1;
    const int mxsiz=a.size()+b.size()-1;
    while(sz<mxsiz)sz<<=1;
    a.resize(sz),b.resize(sz);
    dft(a,1),dft(b,1);
    for(int i=0;i<sz;i++)a[i]*=b[i];
    dft(a,-1);
    a.resize(mxsiz);
    mint iz=mint(sz).inv();
    for(int i=0;i<mxsiz;i++)a[i]*=iz;
    return a;
  }
  template<typename T,std::enable_if_t<is_integral<T>::value>* = nullptr>
  static vector<T>multiply(const vector<T>&a,const vector<T>&b){
    vector<mint>a2(a.size()),b2(b.size());
    for(int i=0;i<(int)a.size();i++)a2[i]=a[i];
    for(int i=0;i<(int)b.size();i++)b2[i]=b[i];
    auto c2=multiply(a2,b2);
    vector<T>c(c2.size());
    for(int i=0;i<(int)c.size();i++)c[i]=c2[i].get();
    return c;
  }
};
template<int m>
int NTT<m>::limit=0;
template<int m>
vector<ModInt<m>>NTT<m>::root=vector<ModInt<m>>();
template<int m>
vector<ModInt<m>>NTT<m>::inv_root=vector<ModInt<m>>();
template<int m>
ModInt<m>NTT<m>::g=ModInt<m>();
/**
 * @brief Number Theoretic Transform(数論変換)
*/