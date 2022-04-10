---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 2 \"Math/modular/modint.hpp\"\ntemplate<long long m>\nstruct\
    \ modint{\n  long long x;\n  constexpr modint():x(0){}\n  constexpr modint(long\
    \ long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n  modint inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n\
    \    while(b){\n      t=a/b;\n      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n \
    \   }\n    return modint(u);\n  }\n  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n  modint\
    \ &operator/=(const modint&p){*this*=p.inv();return *this;}\n  friend modint operator+(const\
    \ modint&l,const modint&r){return modint(l)+=r;}\n  friend modint operator-(const\
    \ modint&l,const modint&r){return modint(l)-=r;}\n  friend modint operator*(const\
    \ modint&l,const modint&r){return modint(l)*=r;}\n  friend modint operator/(const\
    \ modint&l,const modint&r){return modint(l)/=r;}\n  modint operator-()const{return\
    \ modint(-x);}\n  modint operator+()const{return *this;}\n  modint &operator++(){x++;if(x==m)x=0;return\
    \ *this;}\n  modint &operator--(){if(x==0)x=m;x--;return *this;}\n  modint operator++(int){modint\
    \ ret(*this);++*this;return ret;}\n  modint operator--(int){modint ret(*this);--*this;return\
    \ ret;}\n  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}\n\
    \  friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}\n \
    \ modint pow(long long n)const{\n    modint ret(1),mul(x);\n    while(n){\n  \
    \    if(n&1)ret*=mul;\n      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n\
    \  }\n  friend ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n/**\n * @brief modint\n*/\n#line 3 \"Math/others/combinatorics.hpp\"\
    \ntemplate<long long m>\nstruct combination{\n  using mint=modint<m>;\n  vector<mint>dat,idat;\n\
    \  long long mx;\n  combination(long long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n\
    \    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n    idat[mx]/=dat[mx];\n\
    \    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n  }\n  mint com(long\
    \ long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n    return dat[n]*idat[k]*idat[n-k];\n\
    \  }\n  mint fac(long long n){\n    if(n<0)return mint(0);\n    return dat[n];\n\
    \  }\n  mint finv(long long n){\n    if(n<0)return mint(0);\n    return idat[n];\n\
    \  }\n  mint hom(long long n,long long k){\n    return com(n+k-1,k);\n  }\n  mint\
    \ per(long long n,long long k){\n    if(k<0||k>n)return mint(0);\n    return dat[n]*idat[n-k];\n\
    \  }\n};\ntemplate<long long p>\nstruct COMB{\n  vector<vector<modint<p>>>comb;\n\
    \  COMB(){\n    comb.assign(p,vector<modint<p>>(p));\n    comb[0][0]=1;\n    for(int\
    \ i=1;i<p;i++){\n      comb[i][0]=1;\n      for(int j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];\n\
    \    }\n  }\n  modint<p>com(int n,int k){\n    modint<p>ret=1;\n    while(n>0||k>0){\n\
    \      int ni=n%p,ki=k%p;\n      ret*=comb[ni][ki];\n      n/=p;k/=p;\n    }\n\
    \    return ret;\n  }\n};\n/**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\
    \u305B)\n*/\n"
  code: "#pragma once\n#include\"../modular/modint.hpp\"\ntemplate<long long m>\n\
    struct combination{\n  using mint=modint<m>;\n  vector<mint>dat,idat;\n  long\
    \ long mx;\n  combination(long long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n\
    \    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n    idat[mx]/=dat[mx];\n\
    \    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n  }\n  mint com(long\
    \ long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n    return dat[n]*idat[k]*idat[n-k];\n\
    \  }\n  mint fac(long long n){\n    if(n<0)return mint(0);\n    return dat[n];\n\
    \  }\n  mint finv(long long n){\n    if(n<0)return mint(0);\n    return idat[n];\n\
    \  }\n  mint hom(long long n,long long k){\n    return com(n+k-1,k);\n  }\n  mint\
    \ per(long long n,long long k){\n    if(k<0||k>n)return mint(0);\n    return dat[n]*idat[n-k];\n\
    \  }\n};\ntemplate<long long p>\nstruct COMB{\n  vector<vector<modint<p>>>comb;\n\
    \  COMB(){\n    comb.assign(p,vector<modint<p>>(p));\n    comb[0][0]=1;\n    for(int\
    \ i=1;i<p;i++){\n      comb[i][0]=1;\n      for(int j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];\n\
    \    }\n  }\n  modint<p>com(int n,int k){\n    modint<p>ret=1;\n    while(n>0||k>0){\n\
    \      int ni=n%p,ki=k%p;\n      ret*=comb[ni][ki];\n      n/=p;k/=p;\n    }\n\
    \    return ret;\n  }\n};\n/**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\
    \u305B)\n*/"
  dependsOn:
  - Math/modular/modint.hpp
  isVerificationFile: false
  path: Math/others/combinatorics.hpp
  requiredBy:
  - Math/others/lagrange.hpp
  - Math/fps/taylor_shift.hpp
  timestamp: '2022-04-10 15:30:48+01:00'
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
