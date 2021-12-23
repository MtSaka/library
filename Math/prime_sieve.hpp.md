---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
    links: []
  bundledCode: "#line 1 \"Math/prime_sieve.hpp\"\n/**\n * @brief Prime Sieve(\u30A8\
    \u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n*/\ntemplate<typename T>\n\
    struct prime_sieve{\n  vector<T>mpf;\n  vector<T>primes;\n  prime_sieve(T n=1e5){\n\
    \    mpf.resize(n+1,0);\n    iota(mpf.begin(),mpf.end(),0);\n    mpf[0]=mpf[1]=-1;\n\
    \    for(T i=2;i*i<=n;i++){\n      if(mpf[i]==i){\n        for(T j=i*i;j<=n;j+=i){\n\
    \          if(mpf[j]==j)mpf[j]=i;\n        }\n      }\n    }\n    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);\n\
    \  }\n  vector<T>factorize(T n){\n    vector<T>res;\n    T now=n;\n    while(now!=1){\n\
    \      res.push_back(mpf[now]);\n      now/=mpf[now];\n    }\n    return res;\n\
    \  }\n};\n"
  code: "/**\n * @brief Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9)\n*/\ntemplate<typename T>\nstruct prime_sieve{\n  vector<T>mpf;\n  vector<T>primes;\n\
    \  prime_sieve(T n=1e5){\n    mpf.resize(n+1,0);\n    iota(mpf.begin(),mpf.end(),0);\n\
    \    mpf[0]=mpf[1]=-1;\n    for(T i=2;i*i<=n;i++){\n      if(mpf[i]==i){\n   \
    \     for(T j=i*i;j<=n;j+=i){\n          if(mpf[j]==j)mpf[j]=i;\n        }\n \
    \     }\n    }\n    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);\n  }\n\
    \  vector<T>factorize(T n){\n    vector<T>res;\n    T now=n;\n    while(now!=1){\n\
    \      res.push_back(mpf[now]);\n      now/=mpf[now];\n    }\n    return res;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime_sieve.hpp
  requiredBy: []
  timestamp: '2021-12-23 23:12:39+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime_sieve.hpp
layout: document
redirect_from:
- /library/Math/prime_sieve.hpp
- /library/Math/prime_sieve.hpp.html
title: "Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
---
