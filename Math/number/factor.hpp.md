---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ITP1/ITP1_3_D.test.cpp
    title: test/aoj/ITP1/ITP1_3_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Factor Enumeration(\u7D04\u6570\u5217\u6319)"
    links: []
  bundledCode: "#line 1 \"Math/number/factor.hpp\"\nvector<long long>factor(long long\
    \ N){\n  vector<long long>ans;\n  for(long long i=1;i*i<=N;i++){\n    if(N%i==0){\n\
    \      ans.push_back(i);\n      if(i*i!=N)ans.push_back(N/i);\n    }\n  }\n  sort(ans.begin(),ans.end());\n\
    \  return ans;\n}\n/**\n * @brief Factor Enumeration(\u7D04\u6570\u5217\u6319\
    )\n*/\n"
  code: "vector<long long>factor(long long N){\n  vector<long long>ans;\n  for(long\
    \ long i=1;i*i<=N;i++){\n    if(N%i==0){\n      ans.push_back(i);\n      if(i*i!=N)ans.push_back(N/i);\n\
    \    }\n  }\n  sort(ans.begin(),ans.end());\n  return ans;\n}\n/**\n * @brief\
    \ Factor Enumeration(\u7D04\u6570\u5217\u6319)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/factor.hpp
  requiredBy: []
  timestamp: '2022-01-29 16:22:31+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ITP1/ITP1_3_D.test.cpp
documentation_of: Math/number/factor.hpp
layout: document
redirect_from:
- /library/Math/number/factor.hpp
- /library/Math/number/factor.hpp.html
title: "Factor Enumeration(\u7D04\u6570\u5217\u6319)"
---