---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: math/convolution/convolution_mod.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':x:'
    path: math/fps/multipoint_evaluation.hpp
    title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
  - icon: ':x:'
    path: math/fps/polynomial_interpolation.hpp
    title: "Polynomial Interpolation(\u591A\u9805\u5F0F\u88DC\u9593)"
  - icon: ':x:'
    path: math/fps/subset_sum.hpp
    title: Count Subset Sum
  - icon: ':x:'
    path: math/fps/taylor_shift.hpp
    title: "Taylor Shift(\u591A\u9805\u5F0F\u306E\u5E73\u884C\u79FB\u52D5)"
  - icon: ':question:'
    path: math/number/primitive_root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
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
  - icon: ':x:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_interpolation.test.cpp
    title: test/yosupo/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':x:'
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
    document_title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\
      \u89E3)"
    links: []
  bundledCode: "#line 1 \"math/number/fast_prime.hpp\"\nnamespace fastprime{\n  using\
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
    \u901F\u7D20\u56E0\u6570\u5206\u89E3)\n*/\n"
  code: "namespace fastprime{\n  using i128=__uint128_t;\n  long long inner_modmul(const\
    \ long long&x,const long long&y,const long long&p){\n    return i128(x)*y%p;\n\
    \  }\n  long long inner_modpow(long long n,long long m,const long long&p){\n \
    \   long long res=1;\n    while(m){\n      if(m&1)res=inner_modmul(res,n,p);\n\
    \      n=inner_modmul(n,n,p);\n      m>>=1;\n    }\n    return res;\n  }\n  bool\
    \ miller_rabin(const long long&n,const vector<long long>&p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n\
    \    for(long long a:p){\n      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n\
    \      while(t!=n-1&&y!=1&&y!=n-1){\n        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n\
    \      }\n      if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n\
    \  bool is_prime(const long long&n){\n    if(n<=2)return n==2;\n    if(!(n&1))return\
    \ false;\n    if(n<=4759123141)return miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
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
    \u901F\u7D20\u56E0\u6570\u5206\u89E3)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/number/fast_prime.hpp
  requiredBy:
  - math/number/primitive_root.hpp
  - math/fps/fps.hpp
  - math/fps/polynomial_interpolation.hpp
  - math/fps/taylor_shift.hpp
  - math/fps/multipoint_evaluation.hpp
  - math/fps/subset_sum.hpp
  - math/convolution/convolution_mod.hpp
  - math/convolution/convolution.hpp
  - math/convolution/ntt.hpp
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/factorize.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_interpolation.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
documentation_of: math/number/fast_prime.hpp
layout: document
redirect_from:
- /library/math/number/fast_prime.hpp
- /library/math/number/fast_prime.hpp.html
title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
---
