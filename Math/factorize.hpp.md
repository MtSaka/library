---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Prime Factorization(\u7D20\u56E0\u6570\u5206\u89E3)"
    links: []
  bundledCode: "#line 1 \"Math/factorize.hpp\"\n/**\n * @brief Prime Factorization(\u7D20\
    \u56E0\u6570\u5206\u89E3)\n*/\nvector<pair<long long,long long>>factorize(long\
    \ long N){\n  vector<pair<long long,long long>>ans;\n  for(long long i=2;i*i<=N;i++){\n\
    \    if(N%i!=0)continue;\n    long long idx=0;\n    while(N%i==0){\n      idx++;\n\
    \      N/=i;\n    }\n    ans.push_back({i,idx});\n  }\n  if(N!=1)ans.push_back({N,1});\n\
    \  return ans;\n}\n"
  code: "/**\n * @brief Prime Factorization(\u7D20\u56E0\u6570\u5206\u89E3)\n*/\n\
    vector<pair<long long,long long>>factorize(long long N){\n  vector<pair<long long,long\
    \ long>>ans;\n  for(long long i=2;i*i<=N;i++){\n    if(N%i!=0)continue;\n    long\
    \ long idx=0;\n    while(N%i==0){\n      idx++;\n      N/=i;\n    }\n    ans.push_back({i,idx});\n\
    \  }\n  if(N!=1)ans.push_back({N,1});\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/factorize.hpp
  requiredBy: []
  timestamp: '2021-12-23 23:12:39+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/factorize.hpp
layout: document
redirect_from:
- /library/Math/factorize.hpp
- /library/Math/factorize.hpp.html
title: "Prime Factorization(\u7D20\u56E0\u6570\u5206\u89E3)"
---
