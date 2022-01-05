---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1/ITP1_3_D.test.cpp
    title: test/aoj/ITP1/ITP1_3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Factor Enumeration(\u7D04\u6570\u5217\u6319)"
    links: []
  bundledCode: "#line 1 \"Math/factor.hpp\"\n/**\n * @brief Factor Enumeration(\u7D04\
    \u6570\u5217\u6319)\n*/\nvector<long long>factor(long long N){\n  vector<long\
    \ long>ans;\n  for(long long i=1;i*i<=N;i++){\n    if(N%i==0){\n      ans.push_back(i);\n\
    \      if(i*i!=N)ans.push_back(N/i);\n    }\n  }\n  sort(ans.begin(),ans.end());\n\
    \  return ans;\n}\n"
  code: "/**\n * @brief Factor Enumeration(\u7D04\u6570\u5217\u6319)\n*/\nvector<long\
    \ long>factor(long long N){\n  vector<long long>ans;\n  for(long long i=1;i*i<=N;i++){\n\
    \    if(N%i==0){\n      ans.push_back(i);\n      if(i*i!=N)ans.push_back(N/i);\n\
    \    }\n  }\n  sort(ans.begin(),ans.end());\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/factor.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:38:42+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1/ITP1_3_D.test.cpp
documentation_of: Math/factor.hpp
layout: document
redirect_from:
- /library/Math/factor.hpp
- /library/Math/factor.hpp.html
title: "Factor Enumeration(\u7D04\u6570\u5217\u6319)"
---
