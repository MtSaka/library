---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Range Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u533A\u9593\u7BE9)"
    links: []
  bundledCode: "#line 1 \"Math/range_prime_sieve.hpp\"\n/**\n * @brief Range Prime\
    \ Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u533A\u9593\u7BE9)\n\
    */\ntemplate<typename T>\nstruct range_prime_sieve{\n  T l,r,m;\n  vector<T>small;\n\
    \  vector<vector<T>>large;\n  vector<T>mul;\n  range_prime_sieve(T l,T r):l(l),r(r),m(sqrt(r)+1){\n\
    \    large.resize(r-l);\n    small.resize(m);\n    mul.resize(r-l);\n    iota(mul.begin(),mul.end(),l);\n\
    \    iota(small.begin(),small.end(),0);\n    for(T i=2;i*i<r;i++){\n      if(small[i]==i){\n\
    \        for(T j=i*i;j<m;j+=i)if(small[j]==j)small[j]=i;\n        for(T j=(l+i-1)/i*i;j<r;j+=i){\n\
    \          while(mul[j-l]%i==0){\n            mul[j-l]/=i;\n            large[j-l].push_back(i);\n\
    \          }\n        }\n      }\n    }\n  }\n  vector<T>factor(T n){\n    vector<T>res=large[n-l];\n\
    \    if(mul[n-l]!=1)res.push_back(mul[n-l]);\n    return res;\n  }\n};\n"
  code: "/**\n * @brief Range Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u533A\u9593\u7BE9)\n*/\ntemplate<typename T>\nstruct range_prime_sieve{\n\
    \  T l,r,m;\n  vector<T>small;\n  vector<vector<T>>large;\n  vector<T>mul;\n \
    \ range_prime_sieve(T l,T r):l(l),r(r),m(sqrt(r)+1){\n    large.resize(r-l);\n\
    \    small.resize(m);\n    mul.resize(r-l);\n    iota(mul.begin(),mul.end(),l);\n\
    \    iota(small.begin(),small.end(),0);\n    for(T i=2;i*i<r;i++){\n      if(small[i]==i){\n\
    \        for(T j=i*i;j<m;j+=i)if(small[j]==j)small[j]=i;\n        for(T j=(l+i-1)/i*i;j<r;j+=i){\n\
    \          while(mul[j-l]%i==0){\n            mul[j-l]/=i;\n            large[j-l].push_back(i);\n\
    \          }\n        }\n      }\n    }\n  }\n  vector<T>factor(T n){\n    vector<T>res=large[n-l];\n\
    \    if(mul[n-l]!=1)res.push_back(mul[n-l]);\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/range_prime_sieve.hpp
  requiredBy: []
  timestamp: '2021-12-23 23:12:39+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/range_prime_sieve.hpp
layout: document
redirect_from:
- /library/Math/range_prime_sieve.hpp
- /library/Math/range_prime_sieve.hpp.html
title: "Range Prime Sieve(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u533A\u9593\
  \u7BE9)"
---
