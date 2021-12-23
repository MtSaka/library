---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/prime.hpp\"\nbool is_prime(long long N){\n  if(N<2)return\
    \ 0;\n  if(N==2)return 1;\n  if(N%2==0)return 0;\n  for(long long i=3;i*i<=N;i+=2){\n\
    \    if(N%i==0)return 0;\n  }\n  return 1;\n}\nvector<pair<long long,long long>>factorize(long\
    \ long N){\n  vector<pair<long long,long long>>ans;\n  for(long long i=2;i*i<=N;i++){\n\
    \    if(N%i!=0)continue;\n    long long idx=0;\n    while(N%i==0){\n      idx++;\n\
    \      N/=i;\n    }\n    ans.push_back({i,idx});\n  }\n  if(N!=1)ans.push_back({N,1});\n\
    \  return ans;\n}\nvector<long long>factor(long long N){\n  vector<long long>ans;\n\
    \  for(long long i=1;i*i<=N;i++){\n    if(N%i==0){\n      ans.push_back(i);\n\
    \      if(i*i!=N){\n        ans.push_back(N/i);\n      }\n    }\n  }\n  sort(ans.rbegin(),ans.rend());\n\
    \  return ans;\n}\nlong long factor_cnt(long long N){\n  long long ans=1;\n  for(long\
    \ long i=2;i*i<=N;i++){\n    if(N%i==0){\n      int e=0;\n      while(N%i==0){\n\
    \        N/=i;\n        e++;\n      }\n      ans*=e+1;\n    }\n  }\n  if(N!=1)ans*=2;\n\
    \  return ans;\n}\ntemplate<typename T>\nstruct prime_sieve{\n  vector<T>mpf;\n\
    \  vector<T>primes;\n  prime_sieve(T n=1e5){\n    mpf.resize(n+1,0);\n    iota(mpf.begin(),mpf.end(),0);\n\
    \    mpf[0]=mpf[1]=-1;\n    for(T i=2;i*i<=n;i++){\n      if(mpf[i]==i){\n   \
    \     for(T j=i*i;j<=n;j+=i){\n          if(mpf[j]==j)mpf[j]=i;\n        }\n \
    \     }\n    }\n    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);\n  }\n\
    \  vector<T>factorize(T n){\n    vector<T>res;\n    T now=n;\n    while(now!=1){\n\
    \      res.push_back(mpf[now]);\n      now/=mpf[now];\n    }\n    return res;\n\
    \  }\n};\ntemplate<typename T>\nstruct range_prime_sieve{\n  T l,r,m;\n  vector<T>small;\n\
    \  vector<vector<T>>large;\n  vector<T>mul;\n  range_prime_sieve(T l,T r):l(l),r(r),m(sqrt(r)+1){\n\
    \    large.resize(r-l);\n    small.resize(m);\n    mul.resize(r-l);\n    iota(mul.begin(),mul.end(),l);\n\
    \    iota(small.begin(),small.end(),0);\n    for(T i=2;i*i<r;i++){\n      if(small[i]==i){\n\
    \        for(T j=i*i;j<m;j+=i)if(small[j]==j)small[j]=i;\n        for(T j=(l+i-1)/i*i;j<r;j+=i){\n\
    \          while(mul[j-l]%i==0){\n            mul[j-l]/=i;\n            large[j-l].push_back(i);\n\
    \          }\n        }\n      }\n    }\n  }\n  vector<T>factor(T n){\n    vector<T>res=large[n-l];\n\
    \    if(mul[n-l]!=1)res.push_back(mul[n-l]);\n    return res;\n  }\n};\n"
  code: "bool is_prime(long long N){\n  if(N<2)return 0;\n  if(N==2)return 1;\n  if(N%2==0)return\
    \ 0;\n  for(long long i=3;i*i<=N;i+=2){\n    if(N%i==0)return 0;\n  }\n  return\
    \ 1;\n}\nvector<pair<long long,long long>>factorize(long long N){\n  vector<pair<long\
    \ long,long long>>ans;\n  for(long long i=2;i*i<=N;i++){\n    if(N%i!=0)continue;\n\
    \    long long idx=0;\n    while(N%i==0){\n      idx++;\n      N/=i;\n    }\n\
    \    ans.push_back({i,idx});\n  }\n  if(N!=1)ans.push_back({N,1});\n  return ans;\n\
    }\nvector<long long>factor(long long N){\n  vector<long long>ans;\n  for(long\
    \ long i=1;i*i<=N;i++){\n    if(N%i==0){\n      ans.push_back(i);\n      if(i*i!=N){\n\
    \        ans.push_back(N/i);\n      }\n    }\n  }\n  sort(ans.rbegin(),ans.rend());\n\
    \  return ans;\n}\nlong long factor_cnt(long long N){\n  long long ans=1;\n  for(long\
    \ long i=2;i*i<=N;i++){\n    if(N%i==0){\n      int e=0;\n      while(N%i==0){\n\
    \        N/=i;\n        e++;\n      }\n      ans*=e+1;\n    }\n  }\n  if(N!=1)ans*=2;\n\
    \  return ans;\n}\ntemplate<typename T>\nstruct prime_sieve{\n  vector<T>mpf;\n\
    \  vector<T>primes;\n  prime_sieve(T n=1e5){\n    mpf.resize(n+1,0);\n    iota(mpf.begin(),mpf.end(),0);\n\
    \    mpf[0]=mpf[1]=-1;\n    for(T i=2;i*i<=n;i++){\n      if(mpf[i]==i){\n   \
    \     for(T j=i*i;j<=n;j+=i){\n          if(mpf[j]==j)mpf[j]=i;\n        }\n \
    \     }\n    }\n    for(T i=2;i<=n;i++)if(mpf[i]==i)primes.push_back(i);\n  }\n\
    \  vector<T>factorize(T n){\n    vector<T>res;\n    T now=n;\n    while(now!=1){\n\
    \      res.push_back(mpf[now]);\n      now/=mpf[now];\n    }\n    return res;\n\
    \  }\n};\ntemplate<typename T>\nstruct range_prime_sieve{\n  T l,r,m;\n  vector<T>small;\n\
    \  vector<vector<T>>large;\n  vector<T>mul;\n  range_prime_sieve(T l,T r):l(l),r(r),m(sqrt(r)+1){\n\
    \    large.resize(r-l);\n    small.resize(m);\n    mul.resize(r-l);\n    iota(mul.begin(),mul.end(),l);\n\
    \    iota(small.begin(),small.end(),0);\n    for(T i=2;i*i<r;i++){\n      if(small[i]==i){\n\
    \        for(T j=i*i;j<m;j+=i)if(small[j]==j)small[j]=i;\n        for(T j=(l+i-1)/i*i;j<r;j+=i){\n\
    \          while(mul[j-l]%i==0){\n            mul[j-l]/=i;\n            large[j-l].push_back(i);\n\
    \          }\n        }\n      }\n    }\n  }\n  vector<T>factor(T n){\n    vector<T>res=large[n-l];\n\
    \    if(mul[n-l]!=1)res.push_back(mul[n-l]);\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime.hpp
layout: document
redirect_from:
- /library/Math/prime.hpp
- /library/Math/prime.hpp.html
title: Math/prime.hpp
---
