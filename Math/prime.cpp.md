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
  bundledCode: "#line 1 \"Math/prime.cpp\"\nbool is_prime(long long N){\n  if(N<2)return\
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
    \  return ans;\n}\n"
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
    \  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/prime.cpp
layout: document
redirect_from:
- /library/Math/prime.cpp
- /library/Math/prime.cpp.html
title: Math/prime.cpp
---
