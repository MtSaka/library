---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modint.hpp
    title: modint
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/lagrange.hpp
    title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':heavy_check_mark:'
    path: Math/taylor-shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
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
  bundledCode: "#line 2 \"Math/modint.hpp\"\ntemplate<long long m>\nstruct modint{\n\
    \  long long x;\n  modint():x(0){}\n  modint(long long y){\n    if(y<0){\n   \
    \   y%=m;\n      if(y==0)x=y;\n      else x=m+y;\n    }\n    else if(y<m)x=y;\n\
    \    else x=y%m;\n  }\n  modint inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n\
    \    while(b){\n      t=a/b;\n      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n \
    \   }\n    return modint(u);\n  }\n  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n  modint\
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
    \ m;}\n};\n/**\n * @brief modint\n*/\n#line 3 \"Math/combinatorics.hpp\"\ntemplate<long\
    \ long m>\nstruct combination{\n  using mint=modint<m>;\n  vector<mint>dat,idat;\n\
    \  long long mx;\n  combination(long long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n\
    \    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n    idat[mx]/=dat[mx];\n\
    \    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n  }\n  mint com(long\
    \ long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n    return dat[n]*idat[k]*idat[n-k];\n\
    \  }\n  mint fac(long long n){\n    if(n<0)return mint(0);\n    return dat[n];\n\
    \  }\n  mint finv(long long n){\n    if(n<0)return mint(0);\n    return idat[n];\n\
    \  }\n  mint hom(long long n,long long k){\n    return com(n+k-1,k);\n  }\n  mint\
    \ per(long long n,long long k){\n    if(k<0||k>n)return mint(0);\n    return dat[n]*idat[n-k];\n\
    \  }\n};\n/**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\u305B)\n*/\n"
  code: "#pragma once\n#include\"modint.hpp\"\ntemplate<long long m>\nstruct combination{\n\
    \  using mint=modint<m>;\n  vector<mint>dat,idat;\n  long long mx;\n  combination(long\
    \ long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n\
    \    idat[mx]/=dat[mx];\n    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n\
    \  }\n  mint com(long long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n\
    \    return dat[n]*idat[k]*idat[n-k];\n  }\n  mint fac(long long n){\n    if(n<0)return\
    \ mint(0);\n    return dat[n];\n  }\n  mint finv(long long n){\n    if(n<0)return\
    \ mint(0);\n    return idat[n];\n  }\n  mint hom(long long n,long long k){\n \
    \   return com(n+k-1,k);\n  }\n  mint per(long long n,long long k){\n    if(k<0||k>n)return\
    \ mint(0);\n    return dat[n]*idat[n-k];\n  }\n};\n/**\n * @brief Combinatorics(\u7D44\
    \u307F\u5408\u308F\u305B)\n*/"
  dependsOn:
  - Math/modint.hpp
  isVerificationFile: false
  path: Math/combinatorics.hpp
  requiredBy:
  - Math/lagrange.hpp
  - Math/taylor-shift.hpp
  timestamp: '2022-01-11 20:35:27+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/polynomial_taylor_shift.test.cpp
documentation_of: Math/combinatorics.hpp
layout: document
redirect_from:
- /library/Math/combinatorics.hpp
- /library/Math/combinatorics.hpp.html
title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
---
