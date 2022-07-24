---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/convolution/convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/convolution/mod_ntt.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/multipoint_evaluation.hpp
    title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/polynomial_interpolation.hpp
    title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/subset_sum.hpp
    title: Count Subset Sum
  - icon: ':heavy_check_mark:'
    path: Math/fps/taylor_shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
  - icon: ':heavy_check_mark:'
    path: Math/others/combinatorics.hpp
    title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
  - icon: ':warning:'
    path: Math/others/lagrange.hpp
    title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
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
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: modint
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
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief modint\n*/\n"
  code: "#pragma once\ntemplate<int m>\nstruct modint{\n  private:\n  unsigned int\
    \ x;\n  static constexpr unsigned int umod(){return m;}\n  public:\n  static modint\
    \ raw(int v){\n    modint ret;\n    ret.x=v;\n    return ret;\n  }\n  constexpr\
    \ modint():x(0){}\n  constexpr modint(int y){\n    int v=y%m;\n    if(v<0)v+=m;\n\
    \    x=(unsigned int)v;\n  }\n  constexpr modint(long long y){\n    long long\
    \ v=y%(long long)m;\n    if(v<0)v+=m;\n    x=(unsigned int)v;\n  }\n  constexpr\
    \ modint(unsigned int y){\n    x=(unsigned int)(y%umod());\n  }\n  modint& operator++(){x++;if(x==umod())x=0;return\
    \ *this;}\n  modint& operator--(){if(x==0)x=umod();x--;return *this;}\n  modint\
    \ operator++(int){\n    modint ret=*this;\n    ++*this;\n    return ret;\n  }\n\
    \  modint operator--(int){\n    modint ret=*this;\n    --*this;\n    return ret;\n\
    \  }\n  modint& operator+=(const modint&p){if((x+=p.x)>=umod())x-=umod();return\
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
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief modint\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/modular/modint.hpp
  requiredBy:
  - Math/others/lagrange.hpp
  - Math/others/combinatorics.hpp
  - Math/convolution/mod_ntt.hpp
  - Math/convolution/convolution.hpp
  - Math/convolution/ntt.hpp
  - Math/fps/subset_sum.hpp
  - Math/fps/multipoint_evaluation.hpp
  - Math/fps/polynomial_interpolation.hpp
  - Math/fps/taylor_shift.hpp
  - Math/fps/fps.hpp
  timestamp: '2022-07-18 21:10:31+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/lcm_convolution.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
documentation_of: Math/modular/modint.hpp
layout: document
redirect_from:
- /library/Math/modular/modint.hpp
- /library/Math/modular/modint.hpp.html
title: modint
---
