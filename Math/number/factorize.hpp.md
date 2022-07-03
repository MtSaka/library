---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL/NTL_1_A.test.cpp
    title: test/aoj/NTL/NTL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Prime Factorization(\u7D20\u56E0\u6570\u5206\u89E3)"
    links: []
  bundledCode: "#line 1 \"Math/number/factorize.hpp\"\nvector<pair<long long,int>>factorize(long\
    \ long N){\n  vector<pair<long long,int>>ans;\n  for(long long i=2;i*i<=N;i++){\n\
    \    if(N%i!=0)continue;\n    int idx=0;\n    while(N%i==0){\n      idx++;\n \
    \     N/=i;\n    }\n    ans.push_back({i,idx});\n  }\n  if(N!=1)ans.push_back({N,1});\n\
    \  return ans;\n}\n/**\n * @brief Prime Factorization(\u7D20\u56E0\u6570\u5206\
    \u89E3)\n*/\n"
  code: "vector<pair<long long,int>>factorize(long long N){\n  vector<pair<long long,int>>ans;\n\
    \  for(long long i=2;i*i<=N;i++){\n    if(N%i!=0)continue;\n    int idx=0;\n \
    \   while(N%i==0){\n      idx++;\n      N/=i;\n    }\n    ans.push_back({i,idx});\n\
    \  }\n  if(N!=1)ans.push_back({N,1});\n  return ans;\n}\n/**\n * @brief Prime\
    \ Factorization(\u7D20\u56E0\u6570\u5206\u89E3)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/factorize.hpp
  requiredBy: []
  timestamp: '2022-01-29 16:22:31+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL/NTL_1_A.test.cpp
documentation_of: Math/number/factorize.hpp
layout: document
redirect_from:
- /library/Math/number/factorize.hpp
- /library/Math/number/factorize.hpp.html
title: "Prime Factorization(\u7D20\u56E0\u6570\u5206\u89E3)"
---
