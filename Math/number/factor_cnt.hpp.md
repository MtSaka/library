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
  bundledCode: "#line 1 \"Math/number/factor_cnt.hpp\"\ntemplate<typename T>\nint\
    \ factor_cnt(T N){\n  int ans=1;\n  for(T i=2;i*i<=N;i++){\n    if(N%i==0){\n\
    \      int e=0;\n      while(N%i==0){\n        N/=i;\n        e++;\n      }\n\
    \      ans*=e+1;\n    }\n  }\n  if(N!=1)ans*=2;\n  return ans;\n}\n/**\n * @brief\
    \ Factor Count(\u7D04\u6570\u500B\u6570)\n*/\n"
  code: "template<typename T>\nint factor_cnt(T N){\n  int ans=1;\n  for(T i=2;i*i<=N;i++){\n\
    \    if(N%i==0){\n      int e=0;\n      while(N%i==0){\n        N/=i;\n      \
    \  e++;\n      }\n      ans*=e+1;\n    }\n  }\n  if(N!=1)ans*=2;\n  return ans;\n\
    }\n/**\n * @brief Factor Count(\u7D04\u6570\u500B\u6570)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/factor_cnt.hpp
  requiredBy: []
  timestamp: '2022-07-11 11:15:02+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/factor_cnt.hpp
layout: document
redirect_from:
- /library/Math/number/factor_cnt.hpp
- /library/Math/number/factor_cnt.hpp.html
title: "Factor Count(\u7D04\u6570\u500B\u6570)"
---
