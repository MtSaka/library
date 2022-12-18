---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_1_C_2.test.cpp
    title: test/aoj/ALDS1/ALDS1_1_C_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
    links: []
  bundledCode: "#line 1 \"math/number/prime_sieve.hpp\"\ntemplate<typename T>\nstruct\
    \ prime_sieve{\n  vector<T>mpf;\n  vector<T>primes;\n  prime_sieve(T n=1e5){\n\
    \    mpf.resize(n+1,0);\n    iota(mpf.begin(),mpf.end(),0);\n    mpf[0]=mpf[1]=-1;\n\
    \    for(T i=2;i*i<=n;i++){\n      if(mpf[i]==i){\n        for(T j=i*i;j<=n;j+=i){\n\
    \          if(mpf[j]==j)mpf[j]=i;\n        }\n      }\n    }\n    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);\n\
    \  }\n  vector<pair<T,int>>factorize(T n){\n    vector<pair<T,int>>res;\n    T\
    \ now=n;\n    while(now!=1){\n      if(res.size()&&res.back().first==mpf[now])res.back().second++;\n\
    \      else res.emplace_back(mpf[now],1);\n      now/=mpf[now];\n    }\n    return\
    \ res;\n  }\n};\ntemplate<typename T>\nstruct IsPrime{\n  T MAX;\n  vector<bool>isprime;\n\
    \  IsPrime(T MAX):MAX(MAX),isprime(MAX+1,true){\n    isprime[0]=isprime[1]=false;\n\
    \    for(T i=2;i<MAX+1;i++){\n      if(!isprime[i])continue;\n      for(T j=i*i;j<MAX+1;j+=i)isprime[j]=false;\n\
    \    }\n  }\n  bool is_prime(T x){return isprime[x];}\n  vector<T>primes(T m=-1){\n\
    \    if(m==-1)m=MAX;\n    vector<T>res;\n    for(T i=2;i<m+1;i++)if(isprime[i])res.push_back(i);\n\
    \    return res;\n  }\n};\n/**\n * @brief Prime Sieve(\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9)\n*/\n"
  code: "template<typename T>\nstruct prime_sieve{\n  vector<T>mpf;\n  vector<T>primes;\n\
    \  prime_sieve(T n=1e5){\n    mpf.resize(n+1,0);\n    iota(mpf.begin(),mpf.end(),0);\n\
    \    mpf[0]=mpf[1]=-1;\n    for(T i=2;i*i<=n;i++){\n      if(mpf[i]==i){\n   \
    \     for(T j=i*i;j<=n;j+=i){\n          if(mpf[j]==j)mpf[j]=i;\n        }\n \
    \     }\n    }\n    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);\n  }\n\
    \  vector<pair<T,int>>factorize(T n){\n    vector<pair<T,int>>res;\n    T now=n;\n\
    \    while(now!=1){\n      if(res.size()&&res.back().first==mpf[now])res.back().second++;\n\
    \      else res.emplace_back(mpf[now],1);\n      now/=mpf[now];\n    }\n    return\
    \ res;\n  }\n};\ntemplate<typename T>\nstruct IsPrime{\n  T MAX;\n  vector<bool>isprime;\n\
    \  IsPrime(T MAX):MAX(MAX),isprime(MAX+1,true){\n    isprime[0]=isprime[1]=false;\n\
    \    for(T i=2;i<MAX+1;i++){\n      if(!isprime[i])continue;\n      for(T j=i*i;j<MAX+1;j+=i)isprime[j]=false;\n\
    \    }\n  }\n  bool is_prime(T x){return isprime[x];}\n  vector<T>primes(T m=-1){\n\
    \    if(m==-1)m=MAX;\n    vector<T>res;\n    for(T i=2;i<m+1;i++)if(isprime[i])res.push_back(i);\n\
    \    return res;\n  }\n};\n/**\n * @brief Prime Sieve(\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/number/prime_sieve.hpp
  requiredBy: []
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_1_C_2.test.cpp
documentation_of: math/number/prime_sieve.hpp
layout: document
redirect_from:
- /library/math/number/prime_sieve.hpp
- /library/math/number/prime_sieve.hpp.html
title: "Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
---
