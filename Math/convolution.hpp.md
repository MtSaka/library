---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Convolution(\u7573\u307F\u8FBC\u307F)"
    links: []
  bundledCode: "#line 1 \"Math/convolution.hpp\"\n/**\n * @brief Convolution(\u7573\
    \u307F\u8FBC\u307F)\n*/\n#line 1 \"Math/ntt.hpp\"\n/**\n * @brief Number Theoretic\
    \ Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 1 \"Math/modint.hpp\"\n/**\n\
    \ * @brief modint\n*/\ntemplate<long long m>\nstruct modint{\n  long long x;\n\
    \  modint():x(0){}\n  modint(long long y){\n    if(y<0){\n      y%=m;\n      if(y==0)x=y;\n\
    \      else x=m+y;\n    }\n    else if(y<m)x=y;\n    else x=y%m;\n  }\n  modint\
    \ inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n\
    \      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n\
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
    \ m;}\n};\n#line 5 \"Math/ntt.hpp\"\ntemplate<long long m>\nstruct NTT{\n  using\
    \ mint=modint<m>;\n  static modint<m> g;\n  static int limit;\n  static vector<modint<m>>root,inv_root;\n\
    \  static mint primitive_root(const long long&mo){\n    if(mo==167772161)return\
    \ mint(3);\n    if(mo==469762049)return mint(3);\n    if(mo==754974721)return\
    \ mint(11);\n    if(mo==998244353)return mint(3);\n    if(mo==1224736769)return\
    \ mint(3);\n    return mint(0);\n  }\n  static void init(){\n    if(root.empty()){\n\
    \      g=primitive_root(m);\n      long long now=m-1;\n      while(!(now&1))now>>=1,limit++;\n\
    \      root.resize(limit+1,1),inv_root.resize(limit+1,1);\n      root[limit]=g.pow(now);\n\
    \      inv_root[limit]/=root[limit];\n      for(int i=limit-1;i>=0;i--){\n   \
    \     root[i]=root[i+1]*root[i+1];\n        inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
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
    \ i=0;i<a.size();i++)a2[i]=a[i];\n    for(int i=0;i<b.size();i++)b2[i]=b[i];\n\
    \    auto c2=multiply(a2,b2);\n    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n\
    \    return c;\n  }\n};\ntemplate<long long m>\nint NTT<m>::limit=0;\ntemplate<long\
    \ long m>\nvector<modint<m>>NTT<m>::root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nvector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nmodint<m>NTT<m>::g=modint<m>();\n#line 5 \"Math/convolution.hpp\"\nvector<long\
    \ long>convolution(const vector<long long>&a,const vector<long long>&b){\n  const\
    \ int n=a.size(),m=b.size();\n  if(!n||!m)return {};\n  static constexpr unsigned\
    \ long long MOD1=754974721ull,MOD2=167772161ull,MOD3=469762049ull,M2M3=78812994116517889ull,M1M3=354658471880163329ull,M1M2=126663740442542081ull,M1M2M3=560135205046714369ull,i1=190329765ull,i2=58587104,i3=187290749ull;\n\
    \  auto c1=NTT<MOD1>::multiply(a,b);\n  auto c2=NTT<MOD2>::multiply(a,b);\n  auto\
    \ c3=NTT<MOD3>::multiply(a,b);\n  vector<long long>c(n+m-1);\n  static constexpr\
    \ unsigned long long offset[5]={0,0,M1M2M3,2*M1M2M3,3*M1M2M3};\n  for(int i=0;i<n+m-1;i++){\n\
    \    unsigned long long x=0;\n    x+=(c1[i]*i1)%MOD1*M2M3;\n    x+=(c2[i]*i2)%MOD2*M1M3;\n\
    \    x+=(c3[i]*i3)%MOD3*M1M2;\n    long long diff=c1[i]-x%MOD1;\n    if(diff<0)diff+=MOD1;\n\
    \    x-=offset[diff%5];\n    c[i]=x;\n  }\n  return c;\n}\n"
  code: "/**\n * @brief Convolution(\u7573\u307F\u8FBC\u307F)\n*/\n#include\"ntt.hpp\"\
    \nvector<long long>convolution(const vector<long long>&a,const vector<long long>&b){\n\
    \  const int n=a.size(),m=b.size();\n  if(!n||!m)return {};\n  static constexpr\
    \ unsigned long long MOD1=754974721ull,MOD2=167772161ull,MOD3=469762049ull,M2M3=78812994116517889ull,M1M3=354658471880163329ull,M1M2=126663740442542081ull,M1M2M3=560135205046714369ull,i1=190329765ull,i2=58587104,i3=187290749ull;\n\
    \  auto c1=NTT<MOD1>::multiply(a,b);\n  auto c2=NTT<MOD2>::multiply(a,b);\n  auto\
    \ c3=NTT<MOD3>::multiply(a,b);\n  vector<long long>c(n+m-1);\n  static constexpr\
    \ unsigned long long offset[5]={0,0,M1M2M3,2*M1M2M3,3*M1M2M3};\n  for(int i=0;i<n+m-1;i++){\n\
    \    unsigned long long x=0;\n    x+=(c1[i]*i1)%MOD1*M2M3;\n    x+=(c2[i]*i2)%MOD2*M1M3;\n\
    \    x+=(c3[i]*i3)%MOD3*M1M2;\n    long long diff=c1[i]-x%MOD1;\n    if(diff<0)diff+=MOD1;\n\
    \    x-=offset[diff%5];\n    c[i]=x;\n  }\n  return c;\n}"
  dependsOn:
  - Math/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: false
  path: Math/convolution.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:51:06+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/convolution.hpp
layout: document
redirect_from:
- /library/Math/convolution.hpp
- /library/Math/convolution.hpp.html
title: "Convolution(\u7573\u307F\u8FBC\u307F)"
---
