---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/lagrange.cpp
    title: Math/lagrange.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint.cpp\"\ntemplate<long long m>\nstruct modint{\n\
    \  long long x;\n  modint():x(0){}\n  modint(long long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n\
    \  modint inv()const{long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n\
    \      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n\
    \  }\n  modint &operator+=(const modint&p) {if((x+=p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n \
    \ modint &operator*=(const modint&p) {x=x*p.x%m;return *this;}\n  modint &operator/=(const\
    \ modint&p){*this*=p.inv();return *this;}\n  modint operator-()const{return modint(-x);\
    \ }\n  modint operator+(const modint&p)const{return modint(*this)+=p; }\n  modint\
    \ operator-(const modint&p)const{return modint(*this)-=p; }\n  modint operator*(const\
    \ modint&p)const{return modint(*this)*=p; }\n  modint operator/(const modint&p)const{return\
    \ modint(*this)/=p; }\n  bool operator==(const modint&p)const{return x==p.x;}\n\
    \  bool operator!=(const modint&p)const{return x!=p.x;}\n  modint pow(long long\
    \ n) const {\n    modint ret(1),mul(x);\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n  }\n  friend\
    \ istream &operator>>(istream &is, modint &a) {\n    long long t;\n    is>>t;\n\
    \    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n#line 2 \"Math/com.cpp\"\ntemplate<long long m>\nstruct combination{\n\
    \  using mint=modint<m>;\n  vector<mint>dat,idat;\n  long long mx;\n  combination(long\
    \ long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n\
    \    idat[mx]/=dat[mx];\n    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n\
    \  }\n  mint com(long long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n\
    \    return dat[n]*idat[k]*idat[n-k];\n  }\n  mint fac(long long n){\n    if(n<0)return\
    \ mint(0);\n    return dat[n];\n  }\n};\n"
  code: "#include\"modint.cpp\"\ntemplate<long long m>\nstruct combination{\n  using\
    \ mint=modint<m>;\n  vector<mint>dat,idat;\n  long long mx;\n  combination(long\
    \ long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n\
    \    idat[mx]/=dat[mx];\n    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n\
    \  }\n  mint com(long long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n\
    \    return dat[n]*idat[k]*idat[n-k];\n  }\n  mint fac(long long n){\n    if(n<0)return\
    \ mint(0);\n    return dat[n];\n  }\n};"
  dependsOn:
  - Math/modint.cpp
  isVerificationFile: false
  path: Math/com.cpp
  requiredBy:
  - Math/lagrange.cpp
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/com.cpp
layout: document
redirect_from:
- /library/Math/com.cpp
- /library/Math/com.cpp.html
title: Math/com.cpp
---
