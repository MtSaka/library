---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modint.hpp
    title: modint
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/mod_ntt.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
    links: []
  bundledCode: "#line 1 \"Math/ntt.hpp\"\n/**\n * @brief Number Theoretic Transform(\u6570\
    \u8AD6\u5909\u63DB)\n*/\n#line 1 \"Math/modint.hpp\"\n/**\n * @brief modint\n\
    */\ntemplate<long long m>\nstruct modint{\n  long long x;\n  modint():x(0){}\n\
    \  modint(long long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n  modint inv()const{long long\
    \ a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n      swap(a-=t*b,b);\n   \
    \   swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n  modint &operator+=(const\
    \ modint&p) {if((x+=p.x)>=m)x-=m;return *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator*=(const modint&p) {x=x*p.x%m;return *this;}\n  modint\
    \ &operator/=(const modint&p){*this*=p.inv();return *this;}\n  modint operator-()const{return\
    \ modint(-x); }\n  modint operator+(const modint&p)const{return modint(*this)+=p;\
    \ }\n  modint operator-(const modint&p)const{return modint(*this)-=p; }\n  modint\
    \ operator*(const modint&p)const{return modint(*this)*=p; }\n  modint operator/(const\
    \ modint&p)const{return modint(*this)/=p; }\n  bool operator==(const modint&p)const{return\
    \ x==p.x;}\n  bool operator!=(const modint&p)const{return x!=p.x;}\n  modint pow(long\
    \ long n) const {\n    modint ret(1),mul(x);\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n  }\n  friend\
    \ istream &operator>>(istream &is, modint &a) {\n    long long t;\n    is>>t;\n\
    \    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n#line 5 \"Math/ntt.hpp\"\ntemplate<long long m>\nstruct NTT{\n  using\
    \ mint=modint<m>;\n  mint g=2;\n  int limit=0;\n  vector<mint>root,inv_root;\n\
    \  mint primitive_root(long long mo){\n    if(mo==167772161)return mint(3);\n\
    \    if(mo==469762049)return mint(3);\n    if(mo==754974721)return mint(11);\n\
    \    if(mo==998244353)return mint(3);\n    if(mo==1224736769)return mint(3);\n\
    \    return mint(0);\n  }\n  NTT(){\n    g=primitive_root(m);\n    long long now=m-1;\n\
    \    while(!(now&1))now>>=1,limit++;\n    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n\
    \    root[limit]=g.pow(now);\n    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n\
    \      root[i]=root[i+1]*root[i+1];\n      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \    }\n  }\n  void dft(vector<mint>&a,int inv){\n    int sz=a.size();\n    if(sz==1)return;\n\
    \    int mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n\
    \      int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1,mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n    a.resize(sz),b.resize(sz);\n\
    \    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n    dft(a,-1);\n\
    \    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n    a.resize(mxsiz);\n\
    \    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  vector<T>multiply(const vector<T>&a,const vector<T>&b){\n    using\
    \ mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)b2[i]=b[i];\n    auto c2=multiply(move(a2),move(b2));\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n  \
    \  return c;\n  }\n};\n"
  code: "/**\n * @brief Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n\
    #include\"modint.hpp\"\ntemplate<long long m>\nstruct NTT{\n  using mint=modint<m>;\n\
    \  mint g=2;\n  int limit=0;\n  vector<mint>root,inv_root;\n  mint primitive_root(long\
    \ long mo){\n    if(mo==167772161)return mint(3);\n    if(mo==469762049)return\
    \ mint(3);\n    if(mo==754974721)return mint(11);\n    if(mo==998244353)return\
    \ mint(3);\n    if(mo==1224736769)return mint(3);\n    return mint(0);\n  }\n\
    \  NTT(){\n    g=primitive_root(m);\n    long long now=m-1;\n    while(!(now&1))now>>=1,limit++;\n\
    \    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n    root[limit]=g.pow(now);\n\
    \    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n      root[i]=root[i+1]*root[i+1];\n\
    \      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n    }\n  }\n  void dft(vector<mint>&a,int\
    \ inv){\n    int sz=a.size();\n    if(sz==1)return;\n    int mask=sz-1;\n    vector<mint>b(sz);\n\
    \    for(int i=sz>>1;i>=1;i>>=1){\n      int e=__builtin_ffsll(sz/i)-1;\n    \
    \  mint w=1,z=(inv==1?root[e]:inv_root[e]);\n      for(int j=0;j<sz;j+=i){\n \
    \       for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1,mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n    a.resize(sz),b.resize(sz);\n\
    \    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n    dft(a,-1);\n\
    \    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n    a.resize(mxsiz);\n\
    \    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  vector<T>multiply(const vector<T>&a,const vector<T>&b){\n    using\
    \ mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)b2[i]=b[i];\n    auto c2=multiply(move(a2),move(b2));\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n  \
    \  return c;\n  }\n};"
  dependsOn:
  - Math/modint.hpp
  isVerificationFile: false
  path: Math/ntt.hpp
  requiredBy:
  - Math/mod_ntt.hpp
  - Math/convolution.hpp
  - Math/fps.hpp
  timestamp: '2021-12-23 11:59:41+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/convolution_mod.test.cpp
documentation_of: Math/ntt.hpp
layout: document
redirect_from:
- /library/Math/ntt.hpp
- /library/Math/ntt.hpp.html
title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
---
