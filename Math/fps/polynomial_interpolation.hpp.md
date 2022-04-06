---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: Math/fps/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':question:'
    path: Math/modular/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
    links: []
  bundledCode: "#line 2 \"Math/modular/modint.hpp\"\ntemplate<long long m>\nstruct\
    \ modint{\n  long long x;\n  modint():x(0){}\n  modint(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}\n\
    \  modint inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n    while(b){\n     \
    \ t=a/b;\n      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n\
    \  }\n  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n \
    \ modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n  modint\
    \ &operator/=(const modint&p){*this*=p.inv();return *this;}\n  modint operator-()const{return\
    \ modint(-x); }\n  modint operator+(const modint&p)const{return modint(*this)+=p;\
    \ }\n  modint operator-(const modint&p)const{return modint(*this)-=p; }\n  modint\
    \ operator*(const modint&p)const{return modint(*this)*=p; }\n  modint operator/(const\
    \ modint&p)const{return modint(*this)/=p; }\n  bool operator==(const modint&p)const{return\
    \ x==p.x;}\n  bool operator!=(const modint&p)const{return x!=p.x;}\n  modint pow(long\
    \ long n)const{\n    modint ret(1),mul(x);\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n  }\n  friend\
    \ istream &operator>>(istream &is, modint &a) {\n    long long t;\n    is>>t;\n\
    \    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n/**\n * @brief modint\n*/\n#line 3 \"Math/convolution/ntt.hpp\"\ntemplate<long\
    \ long m>\nstruct NTT{\n  using mint=modint<m>;\n  static modint<m> g;\n  static\
    \ int limit;\n  static vector<modint<m>>root,inv_root;\n  static mint primitive_root(const\
    \ long long&mo){\n    if(mo==167772161)return mint(3);\n    if(mo==469762049)return\
    \ mint(3);\n    if(mo==754974721)return mint(11);\n    if(mo==998244353)return\
    \ mint(3);\n    if(mo==1224736769)return mint(3);\n    return mint(0);\n  }\n\
    \  static void init(){\n    if(root.empty()){\n      g=primitive_root(m);\n  \
    \    long long now=m-1;\n      while(!(now&1))now>>=1,limit++;\n      root.resize(limit+1,1),inv_root.resize(limit+1,1);\n\
    \      root[limit]=g.pow(now);\n      inv_root[limit]/=root[limit];\n      for(int\
    \ i=limit-1;i>=0;i--){\n        root[i]=root[i+1]*root[i+1];\n        inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \      }\n    }\n  }\n  NTT(){};\n  static void dft(vector<mint>&a,int inv){\n\
    \    init();\n    const int sz=a.size();\n    if(sz==1)return;\n    const int\
    \ mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n     \
    \ int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  static vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1;\n    const int mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n\
    \    a.resize(sz),b.resize(sz);\n    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n\
    \    dft(a,-1);\n    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n\
    \    a.resize(mxsiz);\n    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  static vector<T>multiply(const vector<T>&a,const vector<T>&b){\n\
    \    using mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int\
    \ i=0;i<(int)a.size();i++)a2[i]=a[i];\n    for(int i=0;i<(int)b.size();i++)b2[i]=b[i];\n\
    \    auto c2=multiply(a2,b2);\n    vector<T>c(c2.size());\n    for(int i=0;i<(int)c.size();i++)c[i]=c2[i].x;\n\
    \    return c;\n  }\n};\ntemplate<long long m>\nint NTT<m>::limit=0;\ntemplate<long\
    \ long m>\nvector<modint<m>>NTT<m>::root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nvector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nmodint<m>NTT<m>::g=modint<m>();\n/**\n * @brief Number Theoretic Transform(\u6570\
    \u8AD6\u5909\u63DB)\n*/\n#line 3 \"Math/fps/fps.hpp\"\ntemplate<long long Mod>\n\
    struct FPS:vector<modint<Mod>>{\n  using mint=modint<Mod>;\n  using vector<mint>::vector;\n\
    \  using vector<mint>::operator=;\n  void shrink(){while(!(*this).empty()&&(*this).back()==mint(0))(*this).pop_back();}\n\
    \  FPS inv(int d=-1)const{\n    NTT<Mod>ntt;\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res{(*this)[0].inv()};\n    for(int m=1;m<d;m<<=1){\n\
    \      FPS f((*this).begin(),(*this).begin()+min(n,2*m));\n      FPS g(res);\n\
    \      f.resize(2*m),g.resize(2*m);\n      ntt.dft(f,1),ntt.dft(g,1);\n      for(int\
    \ i=0;i<2*m;i++)f[i]*=g[i];\n      ntt.dft(f,-1);\n      f.erase(f.begin(),f.begin()+m);\n\
    \      f.resize(2*m);ntt.dft(f,1);\n      for(int i=0;i<2*m;i++)f[i]*=g[i];\n\
    \      ntt.dft(f,-1);\n      mint iz=mint(2*m).inv();iz*=-iz;\n      for(int i=0;i<m;i++)f[i]*=iz;\n\
    \      res.insert(res.end(),f.begin(),f.begin()+m);\n    }\n    res.resize(d);\n\
    \    return res;\n  }\n  FPS operator+(const mint&r)const{return FPS(*this)+=r;}\n\
    \  FPS operator-(const mint&r)const{return FPS(*this)-=r;}\n  FPS operator*(const\
    \ mint&r)const{return FPS(*this)*=r;}\n  FPS operator/(const mint&r)const{return\
    \ FPS(*this)/=r;}\n  FPS operator+(const FPS&r)const{return FPS(*this)+=r;}\n\
    \  FPS operator-(const FPS&r)const{return FPS(*this)-=r;}\n  FPS operator<<(const\
    \ int&d)const{return FPS(*this)<<=d;}\n  FPS operator>>(const int&d)const{return\
    \ FPS(*this)>>=d;}\n  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}\n\
    \  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}\n  FPS operator%(const\
    \ FPS&r)const{return FPS(*this)%=r;}\n  FPS operator-()const{\n    FPS ret(*this);\n\
    \    for(auto &i:ret)i=-i;\n    return ret;\n  }\n  FPS &operator+=(const mint&r){\n\
    \    if((*this).empty())(*this).resize(1);\n    (*this)[0]+=r;\n    return *this;\n\
    \  }\n  FPS &operator-=(const mint&r){\n    if((*this).empty())(*this).resize(1);\n\
    \    (*this)[0]-=r;\n    return *this;\n  }\n  FPS &operator*=(const mint&r){\n\
    \    for(auto &i:*this)i*=r;\n    return *this;\n  }\n  FPS &operator/=(const\
    \ mint&r){\n    (*this)*=r.inv();\n    return *this;\n  }\n  FPS &operator+=(const\
    \ FPS&r){\n    const int n=(*this).size(),m=r.size();\n    (*this).resize(max(n,m));\n\
    \    for(int i=0;i<m;i++)(*this)[i]+=r[i];\n    return *this;\n  }\n  FPS &operator-=(const\
    \ FPS&r){\n    const int n=(*this).size(),m=r.size();\n    (*this).resize(max(n,m));\n\
    \    for(int i=0;i<m;i++)(*this)[i]-=r[i];\n    return *this;\n  }\n  FPS &operator<<=(const\
    \ long long&d){\n    (*this).insert((*this).begin(),d,mint(0));\n    return *this;\n\
    \  }\n  FPS &operator>>=(const long long&d){\n    (*this).erase((*this).begin(),(*this).begin()+d);\n\
    \    return *this;\n  }\n  FPS &operator*=(const FPS&r){\n    (*this)=NTT<Mod>::multiply((*this),r);\n\
    \    return *this;\n  }\n  FPS &operator/=(FPS r){\n    const int n=(*this).size(),m=r.size();\n\
    \    if(n<m){\n      (*this).clear();\n      return *this;\n    }\n    const int\
    \ sz=n-m+1;\n    reverse((*this).begin(),(*this).end());\n    reverse(r.begin(),r.end());\n\
    \    (*this).resize(sz);\n    (*this)*=r.inv(sz);\n    (*this).resize(sz);\n \
    \   reverse((*this).begin(),(*this).end());\n    return (*this);\n  }\n  FPS &operator%=(const\
    \ FPS&r){\n    const int n=(*this).size(),m=r.size();\n    if(n<m)return (*this);\n\
    \    (*this)-=(*this)/r*r;\n    (*this).resize(m-1);\n    shrink();\n    return\
    \ (*this);\n  }\n  pair<FPS,FPS>div_mod(const FPS&r){\n    FPS p=*this/r,q=*this-p*r;\n\
    \    q.shrink();\n    return {p,q};\n  }\n  mint operator()(const mint&x)const{\n\
    \    mint ret(0),w(1);\n    for(auto &e:*this){\n      ret+=e*w;\n      w*=x;\n\
    \    }\n    return ret;\n  }\n  FPS diff()const{\n    const int n=(*this).size();\n\
    \    FPS ret(max(0,n-1));\n    for(int i=1;i<n;i++)ret[i-1]=(*this)[i]*mint(i);\n\
    \    return ret;\n  }\n  FPS integral()const{\n    const int n=(*this).size();\n\
    \    vector<mint>inv(n+1);\n    inv[1]=mint(1);\n    for(int i=2;i<=n;i++)inv[i]=-inv[Mod%i]*mint(Mod/i);\n\
    \    FPS ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=(*this)[i]*inv[i+1];\n  \
    \  return ret;\n  }\n  FPS log(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res=diff()*inv(d);\n    res.resize(d-1);\n    return\
    \ res.integral();\n  }\n  FPS exp(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS f={mint(1)+(*this)[0],(*this)[1]},res{1,1<n?(*this)[1]:0};\n\
    \    for(int m=2;m<d;m<<=1){\n      f.insert(f.end(),(*this).begin()+min(m,n),(*this).begin()+min(n,2*m));\n\
    \      if((int)f.size()<2*m)f.resize(2*m);\n      res=res*(f-res.log(2*m));\n\
    \      res.resize(2*m);\n    }\n    res.resize(d);\n    return res;\n  }\n  FPS\
    \ pow(long long k,int d=-1)const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n\
    \    for(int i=0;i<n;i++){\n      if((*this)[i]!=mint()){\n        mint rev=(*this)[i].inv();\n\
    \        if(i*k>d)return FPS(d,mint(0));\n        FPS ret=(((*this*rev)>>i).log(d)*k).exp(d)*((*this)[i].pow(k));\n\
    \        ret=(ret<<(i*k));\n        ret.resize(d);\n        return ret;\n    \
    \  }\n    }\n    return FPS(d,mint(0));\n  }\n  FPS sqrt(int d=-1,const function<mint(mint)>&get_sqrt=[](mint){return\
    \ mint(1);})const{\n    const int n=(*this).size();\n    if(d==-1)d=n;\n    if((*this)[0]==mint(0)){\n\
    \      for(int i=1;i<n;i++){\n        if((*this)[i]!=mint(0)){\n          if(i&1)return\
    \ {};\n          if(d-i/2<=0)break;\n          auto ret=(*this>>i).sqrt(d-i/2,get_sqrt);\n\
    \          if(ret.empty())return {};\n          ret=ret<<(i/2);\n          if((int)ret.size()<d)ret.resize(d);\n\
    \          return ret;\n        }\n      }\n      return FPS(d);\n    }\n    auto\
    \ sqr=get_sqrt((*this)[0]);\n    if(sqr*sqr!=(*this)[0])return {};\n    FPS ret{sqr};\n\
    \    mint inv2=mint(2).inv();\n    FPS f={(*this)[0]};\n    for(int i=1;i<d;i<<=1){\n\
    \      if(i<n)f.insert(f.end(),(*this).begin()+i,(*this).begin()+min(n,i<<1));\n\
    \      if((int)f.size()<(i<<1))f.resize(i<<1);\n      ret=(ret+f*ret.inv(i<<1))*inv2;\n\
    \    }\n    ret.resize(d);\n    return ret;\n  }\n};\n/**\n * @brief Formal Power\
    \ Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n*/\n#line 3 \"Math/fps/polynomial_interpolation.hpp\"\
    \ntemplate<long long Mod>\nFPS<Mod>polynominal_interpolation(const vector<modint<Mod>>&xs,const\
    \ vector<modint<Mod>>&ys){\n  const int n=xs.size();\n  int sz=1;\n  while(sz<n)sz<<=1;\n\
    \  vector<FPS<Mod>>mul(sz*2,{1});\n  for(int i=0;i<n;i++)mul[i+sz]={-xs[i],modint<Mod>(1)};\n\
    \  for(int i=sz;i-->1;)mul[i]=mul[i<<1]*mul[i<<1|1];\n  vector<FPS<Mod>>g(2*sz);\n\
    \  g[1]=mul[1].diff()%mul[1];\n  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%mul[i];\n\
    \  for(int i=0;i<n;i++)g[sz+i]={ys[i]/g[sz+i][0]};\n  for(int i=sz;i-->1;)g[i]=g[i<<1]*mul[i<<1|1]+g[i<<1|1]*mul[i<<1];\n\
    \  return g[1];\n}\n/**\n * @brief Polynomial Interpolation(\u591A\u9805\u5F0F\
    \u88DC\u9593)\n*/\n"
  code: "#pragma once\n#include\"fps.hpp\"\ntemplate<long long Mod>\nFPS<Mod>polynominal_interpolation(const\
    \ vector<modint<Mod>>&xs,const vector<modint<Mod>>&ys){\n  const int n=xs.size();\n\
    \  int sz=1;\n  while(sz<n)sz<<=1;\n  vector<FPS<Mod>>mul(sz*2,{1});\n  for(int\
    \ i=0;i<n;i++)mul[i+sz]={-xs[i],modint<Mod>(1)};\n  for(int i=sz;i-->1;)mul[i]=mul[i<<1]*mul[i<<1|1];\n\
    \  vector<FPS<Mod>>g(2*sz);\n  g[1]=mul[1].diff()%mul[1];\n  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%mul[i];\n\
    \  for(int i=0;i<n;i++)g[sz+i]={ys[i]/g[sz+i][0]};\n  for(int i=sz;i-->1;)g[i]=g[i<<1]*mul[i<<1|1]+g[i<<1|1]*mul[i<<1];\n\
    \  return g[1];\n}\n/**\n * @brief Polynomial Interpolation(\u591A\u9805\u5F0F\
    \u88DC\u9593)\n*/"
  dependsOn:
  - Math/fps/fps.hpp
  - Math/convolution/ntt.hpp
  - Math/modular/modint.hpp
  isVerificationFile: false
  path: Math/fps/polynomial_interpolation.hpp
  requiredBy: []
  timestamp: '2022-04-06 13:48:48+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/polynomial_interpolation.test.cpp
documentation_of: Math/fps/polynomial_interpolation.hpp
layout: document
redirect_from:
- /library/Math/fps/polynomial_interpolation.hpp
- /library/Math/fps/polynomial_interpolation.hpp.html
title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
---
