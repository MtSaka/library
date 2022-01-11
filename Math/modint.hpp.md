---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/combinatorics.hpp
    title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
  - icon: ':warning:'
    path: Math/convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':warning:'
    path: Math/lagrange.hpp
    title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':heavy_check_mark:'
    path: Math/mod_ntt.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: Math/taylor-shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
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
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: modint
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
    \ m;}\n};\n/**\n * @brief modint\n*/\n"
  code: "#pragma once\ntemplate<long long m>\nstruct modint{\n  long long x;\n  modint():x(0){}\n\
    \  modint(long long y){\n    if(y<0){\n      y%=m;\n      if(y==0)x=y;\n     \
    \ else x=m+y;\n    }\n    else if(y<m)x=y;\n    else x=y%m;\n  }\n  modint inv()const{\n\
    \    long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n      swap(a-=t*b,b);\n\
    \      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n  modint &operator+=(const\
    \ modint&p){if((x+=p.x)>=m)x-=m;return *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n\
    \  modint &operator/=(const modint&p){*this*=p.inv();return *this;}\n  modint\
    \ operator-()const{return modint(-x); }\n  modint operator+(const modint&p)const{return\
    \ modint(*this)+=p; }\n  modint operator-(const modint&p)const{return modint(*this)-=p;\
    \ }\n  modint operator*(const modint&p)const{return modint(*this)*=p; }\n  modint\
    \ operator/(const modint&p)const{return modint(*this)/=p; }\n  bool operator==(const\
    \ modint&p)const{return x==p.x;}\n  bool operator!=(const modint&p)const{return\
    \ x!=p.x;}\n  modint pow(long long n)const{\n    modint ret(1),mul(x);\n    while(n){\n\
    \      if(n&1)ret*=mul;\n      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n\
    \  }\n  friend ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n/**\n * @brief modint\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.hpp
  requiredBy:
  - Math/taylor-shift.hpp
  - Math/mod_ntt.hpp
  - Math/convolution.hpp
  - Math/fps.hpp
  - Math/ntt.hpp
  - Math/combinatorics.hpp
  - Math/lagrange.hpp
  timestamp: '2022-01-11 20:35:27+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: Math/modint.hpp
layout: document
redirect_from:
- /library/Math/modint.hpp
- /library/Math/modint.hpp.html
title: modint
---
