---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modular/modint.hpp
    title: modint
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/fps/taylor_shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
  - icon: ':warning:'
    path: Math/others/lagrange.hpp
    title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
    links: []
  bundledCode: "#line 2 \"Math/modular/modint.hpp\"\ntemplate<int m>\nstruct modint{\n\
    \  private:\n  unsigned int x;\n  static constexpr unsigned int umod(){return\
    \ m;}\n  public:\n  static modint raw(int v){\n    modint ret;\n    ret.x=v;\n\
    \    return ret;\n  }\n  constexpr modint():x(0){}\n  constexpr modint(int y){\n\
    \    int v=y%m;\n    if(v<0)v+=m;\n    x=(unsigned int)v;\n  }\n  constexpr modint(long\
    \ long y){\n    long long v=y%(long long)m;\n    if(v<0)v+=m;\n    x=(unsigned\
    \ int)v;\n  }\n  constexpr modint(unsigned int y){\n    x=(unsigned int)(y%umod());\n\
    \  }\n  modint& operator++(){x++;if(x==umod())x=0;return *this;}\n  modint& operator--(){if(x==0)x=umod();x--;return\
    \ *this;}\n  modint operator++(int){\n    modint ret=*this;\n    ++*this;\n  \
    \  return ret;\n  }\n  modint operator--(int){\n    modint ret=*this;\n    --*this;\n\
    \    return ret;\n  }\n  modint& operator+=(const modint&p){if((x+=p.x)>=umod())x-=umod();return\
    \ *this;}\n  modint& operator-=(const modint&p){if((x-=p.x)>=umod())x+=umod();return\
    \ *this;}\n  modint& operator*=(const modint&p){\n    unsigned long long y=x;\n\
    \    y*=p.x;\n    x=(unsigned int)(y%umod());\n    return *this;\n  }\n  modint&\
    \ operator/=(const modint&p){return *this*=p.inv();}\n  modint operator+()const{return\
    \ *this;}\n  modint operator-()const{return modint()-*this;}\n  modint pow(long\
    \ long n)const{\n    modint ret(1),mul=*this;\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  modint inv()const{\n\
    \    long long a=x,b=m,u=1,v=0;\n    while(b){\n      long long t=a/b;\n     \
    \ swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n\
    \  friend modint operator+(const modint&l,const modint&r){return modint(l)+=r;}\n\
    \  friend modint operator-(const modint&l,const modint&r){return modint(l)-=r;}\n\
    \  friend modint operator*(const modint&l,const modint&r){return modint(l)*=r;}\n\
    \  friend modint operator/(const modint&l,const modint&r){return modint(l)/=r;}\n\
    \  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}\n \
    \ friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}\n  friend\
    \ ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.val();\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint(t);\n    return (is);\n  }\n  static constexpr int get_mod(){return\
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief modint\n*/\n#line\
    \ 3 \"Math/others/combinatorics.hpp\"\ntemplate<int m>\nstruct combination{\n\
    \  using mint=modint<m>;\n  private:\n  static vector<mint>dat,idat;\n  inline\
    \ static void extend(int sz){\n    if((int)dat.size()<sz+1){\n      int pre_sz=max<int>(1,dat.size());\n\
    \      dat.resize(sz+1,1);\n      idat.resize(sz+1,1);\n      for(int i=pre_sz;i<=sz;i++)dat[i]=dat[i-1]*i;\n\
    \      idat[sz]=1/dat[sz];\n      for(int i=sz-1;i>=pre_sz;i--)idat[i]=idat[i+1]*(i+1);\n\
    \    }\n  }\n  public:\n  combination(int sz=0){extend(sz);}\n  template<typename\
    \ T>\n  static inline mint fac(T n){\n    if(n<0)return mint();\n    extend(n);\n\
    \    return dat[n];\n  }\n  template<typename T>\n  static inline mint finv(T\
    \ n){\n    if(n<0)return mint();\n    extend(n);\n    return idat[n];\n  }\n \
    \ template<typename T,typename U>\n  static mint com(T n,U k){\n    if(k<0||n<k)return\
    \ mint();\n    return fac(n)*finv(k)*finv(n-k);\n  }\n  template<typename T,typename\
    \ U>\n  static mint hom(T n,U k){\n    if(n<0||k<0)return mint();\n    return\
    \ k==0?1:com(n+k-1,k);\n  }\n  template<typename T,typename U>\n  static mint\
    \ per(T n,U k){\n    if(k<0||n<k)return mint();\n    return fac(n)*finv(n-k);\n\
    \  }\n};\ntemplate<int m>\nvector<modint<m>>combination<m>::dat=vector<modint<m>>();\n\
    template<int m>\nvector<modint<m>>combination<m>::idat=vector<modint<m>>();\n\
    template<long long p>\nstruct COMB{\n  private:\n  static vector<vector<modint<p>>>comb;\n\
    \  static void init(){\n    if(!comb.empty())return;\n    comb.assign(p,vector<modint<p>>(p));\n\
    \    comb[0][0]=1;\n    for(int i=1;i<p;i++){\n      comb[i][0]=1;\n      for(int\
    \ j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];\n    }\n  }\n  public:\n\
    \  COMB(){\n    init();\n  }\n  modint<p>com(int n,int k){\n    init();\n    modint<p>ret=1;\n\
    \    while(n>0||k>0){\n      int ni=n%p,ki=k%p;\n      ret*=comb[ni][ki];\n  \
    \    n/=p;k/=p;\n    }\n    return ret;\n  }\n};\ntemplate<long long p>\nvector<vector<modint<p>>>COMB<p>::comb=vector<vector<modint<p>>>();\n\
    /**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\u305B)\n*/\n"
  code: "#pragma once\n#include\"../modular/modint.hpp\"\ntemplate<int m>\nstruct\
    \ combination{\n  using mint=modint<m>;\n  private:\n  static vector<mint>dat,idat;\n\
    \  inline static void extend(int sz){\n    if((int)dat.size()<sz+1){\n      int\
    \ pre_sz=max<int>(1,dat.size());\n      dat.resize(sz+1,1);\n      idat.resize(sz+1,1);\n\
    \      for(int i=pre_sz;i<=sz;i++)dat[i]=dat[i-1]*i;\n      idat[sz]=1/dat[sz];\n\
    \      for(int i=sz-1;i>=pre_sz;i--)idat[i]=idat[i+1]*(i+1);\n    }\n  }\n  public:\n\
    \  combination(int sz=0){extend(sz);}\n  template<typename T>\n  static inline\
    \ mint fac(T n){\n    if(n<0)return mint();\n    extend(n);\n    return dat[n];\n\
    \  }\n  template<typename T>\n  static inline mint finv(T n){\n    if(n<0)return\
    \ mint();\n    extend(n);\n    return idat[n];\n  }\n  template<typename T,typename\
    \ U>\n  static mint com(T n,U k){\n    if(k<0||n<k)return mint();\n    return\
    \ fac(n)*finv(k)*finv(n-k);\n  }\n  template<typename T,typename U>\n  static\
    \ mint hom(T n,U k){\n    if(n<0||k<0)return mint();\n    return k==0?1:com(n+k-1,k);\n\
    \  }\n  template<typename T,typename U>\n  static mint per(T n,U k){\n    if(k<0||n<k)return\
    \ mint();\n    return fac(n)*finv(n-k);\n  }\n};\ntemplate<int m>\nvector<modint<m>>combination<m>::dat=vector<modint<m>>();\n\
    template<int m>\nvector<modint<m>>combination<m>::idat=vector<modint<m>>();\n\
    template<long long p>\nstruct COMB{\n  private:\n  static vector<vector<modint<p>>>comb;\n\
    \  static void init(){\n    if(!comb.empty())return;\n    comb.assign(p,vector<modint<p>>(p));\n\
    \    comb[0][0]=1;\n    for(int i=1;i<p;i++){\n      comb[i][0]=1;\n      for(int\
    \ j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];\n    }\n  }\n  public:\n\
    \  COMB(){\n    init();\n  }\n  modint<p>com(int n,int k){\n    init();\n    modint<p>ret=1;\n\
    \    while(n>0||k>0){\n      int ni=n%p,ki=k%p;\n      ret*=comb[ni][ki];\n  \
    \    n/=p;k/=p;\n    }\n    return ret;\n  }\n};\ntemplate<long long p>\nvector<vector<modint<p>>>COMB<p>::comb=vector<vector<modint<p>>>();\n\
    /**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\u305B)\n*/"
  dependsOn:
  - Math/modular/modint.hpp
  isVerificationFile: false
  path: Math/others/combinatorics.hpp
  requiredBy:
  - Math/others/lagrange.hpp
  - Math/fps/taylor_shift.hpp
  timestamp: '2022-07-18 22:46:16+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/polynomial_taylor_shift.test.cpp
documentation_of: Math/others/combinatorics.hpp
layout: document
redirect_from:
- /library/Math/others/combinatorics.hpp
- /library/Math/others/combinatorics.hpp.html
title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
---
