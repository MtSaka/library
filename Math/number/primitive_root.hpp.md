---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modular/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
  - icon: ':question:'
    path: Math/number/fast_prime.hpp
    title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Math/convolution/convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/convolution/mod_ntt.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: Math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: Math/fps/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/multipoint_evaluation.hpp
    title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
  - icon: ':heavy_check_mark:'
    path: Math/fps/polynomial_interpolation.hpp
    title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':x:'
    path: Math/fps/subset_sum.hpp
    title: Count Subset Sum
  - icon: ':heavy_check_mark:'
    path: Math/fps/taylor_shift.hpp
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
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/number/fast_prime.hpp\"\nnamespace fastprime{\n  using\
    \ i128=__uint128_t;\n  long long inner_modmul(const long long&x,const long long&y,const\
    \ long long&p){\n    return i128(x)*y%p;\n  }\n  long long inner_modpow(long long\
    \ n,long long m,const long long&p){\n    long long res=1;\n    while(m){\n   \
    \   if(m&1)res=inner_modmul(res,n,p);\n      n=inner_modmul(n,n,p);\n      m>>=1;\n\
    \    }\n    return res;\n  }\n  bool miller_rabin(const long long&n,const vector<long\
    \ long>&p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n    for(long long a:p){\n\
    \      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n      while(t!=n-1&&y!=1&&y!=n-1){\n\
    \        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n      }\n   \
    \   if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n  bool is_prime(const\
    \ long long&n){\n    if(n<=2)return n==2;\n    if(!(n&1))return false;\n    if(n<=4759123141)return\
    \ miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \  }\n  long long factor(const long long&n){\n    if(!(n&1))return 2;\n    else\
    \ if(is_prime(n))return n;\n    int c=2;\n    while(true){\n      auto f=[&](long\
    \ long x){\n        x=inner_modmul(x,x,n)+c;\n        if(x>=n)x-=n;\n        return\
    \ x;\n      };\n      long long x=c,g=1,q=1,xs,y;\n      int m=128;\n      int\
    \ l=1;\n      while(g==1){\n        y=x;\n        for(int i=1;i<l;i++)x=f(x);\n\
    \        int k=0;\n        while(k<l&&g==1){\n          xs=x;\n          for(int\
    \ i=0;i<m&&i<l-k;i++){\n            x=f(x);\n            q=inner_modmul(q,llabs(y-x),n);\n\
    \          }\n          g=__gcd(q,n);\n          k+=m;\n        }\n        l*=2;\n\
    \      }\n      if(g==n){\n        do{\n          xs=f(xs);\n          g=__gcd(llabs(xs-y),n);\n\
    \        }while(g==1);\n      }\n      if(g!=n)return g;\n      c++;\n    }\n\
    \  }\n  vector<long long>factorize_sub(const long long&n){\n    if(n==1)return\
    \ {};\n    long long p=factor(n);\n    if(p==n)return {p};\n    vector<long long>l=factorize_sub(n/p);\n\
    \    vector<long long>r=factorize_sub(p);\n    l.insert(l.end(),r.begin(),r.end());\n\
    \    return l;\n  }\n  vector<long long>factorize(const long long&n,const bool&sorted=true){\n\
    \    vector<long long>res=factorize_sub(n);\n    if(sorted)sort(res.begin(),res.end());\n\
    \    return res;\n  }\n} // namespace fastprime\n/**\n * @brief Fast Prime Factorization(\u9AD8\
    \u901F\u7D20\u56E0\u6570\u5206\u89E3)\n*/\n#line 2 \"Math/modular/modpow.hpp\"\
    \ntemplate<typename T,typename S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n\
    \    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n\
    \ * @brief Mod Pow(\u3079\u304D\u4E57)\n*/\n#line 3 \"Math/number/primitive_root.hpp\"\
    \nint primitive_root(int n){\n  if(n==2)return 1;\n  if(n==167772161)return 3;\n\
    \  if(n==469762049)return 3;\n  if(n==754974721)return 11;\n  if(n==998244353)return\
    \ 3;\n  if(n==1224736769)return 3;\n  auto divs=fastprime::factorize(n-1);\n \
    \ divs.erase(unique(divs.begin(),divs.end()),divs.end());\n  for(int g=2;;g++){\n\
    \    bool ok=true;\n    for(int d:divs){\n      if(modpow(g,(n-1)/d,n)==1){\n\
    \        ok=false;\n        break;\n      }\n    }\n    if(ok)return g;\n  }\n\
    }\n"
  code: "#include\"fast_prime.hpp\"\n#include\"../modular/modpow.hpp\"\nint primitive_root(int\
    \ n){\n  if(n==2)return 1;\n  if(n==167772161)return 3;\n  if(n==469762049)return\
    \ 3;\n  if(n==754974721)return 11;\n  if(n==998244353)return 3;\n  if(n==1224736769)return\
    \ 3;\n  auto divs=fastprime::factorize(n-1);\n  divs.erase(unique(divs.begin(),divs.end()),divs.end());\n\
    \  for(int g=2;;g++){\n    bool ok=true;\n    for(int d:divs){\n      if(modpow(g,(n-1)/d,n)==1){\n\
    \        ok=false;\n        break;\n      }\n    }\n    if(ok)return g;\n  }\n\
    }"
  dependsOn:
  - Math/number/fast_prime.hpp
  - Math/modular/modpow.hpp
  isVerificationFile: false
  path: Math/number/primitive_root.hpp
  requiredBy:
  - Math/fps/subset_sum.hpp
  - Math/fps/polynomial_interpolation.hpp
  - Math/fps/taylor_shift.hpp
  - Math/fps/fps.hpp
  - Math/fps/multipoint_evaluation.hpp
  - Math/convolution/mod_ntt.hpp
  - Math/convolution/ntt.hpp
  - Math/convolution/convolution.hpp
  timestamp: '2022-11-14 23:10:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
documentation_of: Math/number/primitive_root.hpp
layout: document
redirect_from:
- /library/Math/number/primitive_root.hpp
- /library/Math/number/primitive_root.hpp.html
title: Math/number/primitive_root.hpp
---
