---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/fast-prime.cpp\"\nnamespace fastprime{\n  using i128=__uint128_t;\n\
    \  long long inner_modmul(long long x,long long y,long long p){\n    return i128(x)*y%p;\n\
    \  }\n  long long inner_modpow(long long n,long long m,long long p){\n    long\
    \ long res=1;\n    while(m){\n      if(m&1)res=inner_modmul(res,n,p);\n      n=inner_modmul(n,n,p);\n\
    \      m>>=1;\n    }\n    return res;\n  }\n  bool miller_rabin(long long n,vector<long\
    \ long>p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n    for(long long a:p){\n\
    \      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n      while(t!=n-1&&y!=1&&y!=n-1){\n\
    \        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n      }\n   \
    \   if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n  bool is_prime(long\
    \ long n){\n    if(n<=2)return n==2;\n    if(!(n&1))return false;\n    if(n<=4759123141)return\
    \ miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \  }\n  long long factor(long long n){\n    if(!(n&1))return 2;\n    else if(is_prime(n))return\
    \ n;\n    int c=2;\n    while(true){\n      auto f=[&](long long x){\n       \
    \ x=inner_modmul(x,x,n)+c;\n        if(x>=n)x-=n;\n        return x;\n      };\n\
    \      long long x=c,g=1,q=1,xs,y;\n      int m=128;\n      int l=1;\n      while(g==1){\n\
    \        y=x;\n        for(int i=1;i<l;i++)x=f(x);\n        int k=0;\n       \
    \ while(k<l&&g==1){\n          xs=x;\n          for(int i=0;i<m&&i<l-k;i++){\n\
    \            x=f(x);\n            q=inner_modmul(q,llabs(y-x),n);\n          }\n\
    \          g=__gcd(q,n);\n          k+=m;\n        }\n        l*=2;\n      }\n\
    \      if(g==n){\n        do{\n          xs=f(xs);\n          g=__gcd(llabs(xs-y),n);\n\
    \        }while(g==1);\n      }\n      if(g!=n)return g;\n      c++;\n    }\n\
    \  }\n  vector<long long>factorize_sub(long long n){\n    if(n==1)return {};\n\
    \    long long p=factor(n);\n    if(p==n)return {p};\n    vector<long long>l=factorize_sub(n/p);\n\
    \    vector<long long>r=factorize_sub(p);\n    l.insert(l.end(),r.begin(),r.end());\n\
    \    return l;\n  }\n  vector<long long>factorize(long long n,bool sorted=true){\n\
    \    vector<long long>res=factorize_sub(n);\n    if(sorted)sort(res.begin(),res.end());\n\
    \    return res;\n  }\n};\n"
  code: "namespace fastprime{\n  using i128=__uint128_t;\n  long long inner_modmul(long\
    \ long x,long long y,long long p){\n    return i128(x)*y%p;\n  }\n  long long\
    \ inner_modpow(long long n,long long m,long long p){\n    long long res=1;\n \
    \   while(m){\n      if(m&1)res=inner_modmul(res,n,p);\n      n=inner_modmul(n,n,p);\n\
    \      m>>=1;\n    }\n    return res;\n  }\n  bool miller_rabin(long long n,vector<long\
    \ long>p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n    for(long long a:p){\n\
    \      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n      while(t!=n-1&&y!=1&&y!=n-1){\n\
    \        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n      }\n   \
    \   if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n  bool is_prime(long\
    \ long n){\n    if(n<=2)return n==2;\n    if(!(n&1))return false;\n    if(n<=4759123141)return\
    \ miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \  }\n  long long factor(long long n){\n    if(!(n&1))return 2;\n    else if(is_prime(n))return\
    \ n;\n    int c=2;\n    while(true){\n      auto f=[&](long long x){\n       \
    \ x=inner_modmul(x,x,n)+c;\n        if(x>=n)x-=n;\n        return x;\n      };\n\
    \      long long x=c,g=1,q=1,xs,y;\n      int m=128;\n      int l=1;\n      while(g==1){\n\
    \        y=x;\n        for(int i=1;i<l;i++)x=f(x);\n        int k=0;\n       \
    \ while(k<l&&g==1){\n          xs=x;\n          for(int i=0;i<m&&i<l-k;i++){\n\
    \            x=f(x);\n            q=inner_modmul(q,llabs(y-x),n);\n          }\n\
    \          g=__gcd(q,n);\n          k+=m;\n        }\n        l*=2;\n      }\n\
    \      if(g==n){\n        do{\n          xs=f(xs);\n          g=__gcd(llabs(xs-y),n);\n\
    \        }while(g==1);\n      }\n      if(g!=n)return g;\n      c++;\n    }\n\
    \  }\n  vector<long long>factorize_sub(long long n){\n    if(n==1)return {};\n\
    \    long long p=factor(n);\n    if(p==n)return {p};\n    vector<long long>l=factorize_sub(n/p);\n\
    \    vector<long long>r=factorize_sub(p);\n    l.insert(l.end(),r.begin(),r.end());\n\
    \    return l;\n  }\n  vector<long long>factorize(long long n,bool sorted=true){\n\
    \    vector<long long>res=factorize_sub(n);\n    if(sorted)sort(res.begin(),res.end());\n\
    \    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/fast-prime.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/fast-prime.cpp
layout: document
redirect_from:
- /library/Math/fast-prime.cpp
- /library/Math/fast-prime.cpp.html
title: Math/fast-prime.cpp
---