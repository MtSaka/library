---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Factor Count(\u7D04\u6570\u500B\u6570)"
    links: []
  bundledCode: "#line 1 \"Math/factor_cnt.hpp\"\nlong long factor_cnt(long long N){\n\
    \  long long ans=1;\n  for(long long i=2;i*i<=N;i++){\n    if(N%i==0){\n     \
    \ int e=0;\n      while(N%i==0){\n        N/=i;\n        e++;\n      }\n     \
    \ ans*=e+1;\n    }\n  }\n  if(N!=1)ans*=2;\n  return ans;\n}\n/**\n * @brief Factor\
    \ Count(\u7D04\u6570\u500B\u6570)\n*/\n"
  code: "long long factor_cnt(long long N){\n  long long ans=1;\n  for(long long i=2;i*i<=N;i++){\n\
    \    if(N%i==0){\n      int e=0;\n      while(N%i==0){\n        N/=i;\n      \
    \  e++;\n      }\n      ans*=e+1;\n    }\n  }\n  if(N!=1)ans*=2;\n  return ans;\n\
    }\n/**\n * @brief Factor Count(\u7D04\u6570\u500B\u6570)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/factor_cnt.hpp
  requiredBy: []
  timestamp: '2022-01-11 21:13:55+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/factor_cnt.hpp
layout: document
redirect_from:
- /library/Math/factor_cnt.hpp
- /library/Math/factor_cnt.hpp.html
title: "Factor Count(\u7D04\u6570\u500B\u6570)"
---
