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
  bundledCode: "#line 1 \"Math/phi.cpp\"\nlong long phi(long long n){\n  long long\
    \ ans=n;\n  for(long long i=2;i*i<=n;i++){\n    if(n%i==0){\n      ans/=i;\n \
    \     ans*=i-1;\n      while(n%i==0)n/=i;\n    }\n  }\n  if(n>1){\n    ans/=n;\n\
    \    ans*=(n-1);\n  }\n  return ans;\n}\n"
  code: "long long phi(long long n){\n  long long ans=n;\n  for(long long i=2;i*i<=n;i++){\n\
    \    if(n%i==0){\n      ans/=i;\n      ans*=i-1;\n      while(n%i==0)n/=i;\n \
    \   }\n  }\n  if(n>1){\n    ans/=n;\n    ans*=(n-1);\n  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/phi.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/phi.cpp
layout: document
redirect_from:
- /library/Math/phi.cpp
- /library/Math/phi.cpp.html
title: Math/phi.cpp
---
