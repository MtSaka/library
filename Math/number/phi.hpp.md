---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL/NTL_1_D.test.cpp
    title: test/aoj/NTL/NTL_1_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Euler's Totient Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
      \u95A2\u6570)"
    links: []
  bundledCode: "#line 1 \"Math/number/phi.hpp\"\nlong long phi(long long n){\n  long\
    \ long ans=n;\n  for(long long i=2;i*i<=n;i++){\n    if(n%i==0){\n      ans/=i;ans*=i-1;\n\
    \      while(n%i==0)n/=i;\n    }\n  }\n  if(n>1)ans/=n,ans*=(n-1);\n  return ans;\n\
    }\n/**\n * @brief Euler's Totient Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
    \u95A2\u6570)\n*/\n"
  code: "long long phi(long long n){\n  long long ans=n;\n  for(long long i=2;i*i<=n;i++){\n\
    \    if(n%i==0){\n      ans/=i;ans*=i-1;\n      while(n%i==0)n/=i;\n    }\n  }\n\
    \  if(n>1)ans/=n,ans*=(n-1);\n  return ans;\n}\n/**\n * @brief Euler's Totient\
    \ Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/phi.hpp
  requiredBy: []
  timestamp: '2022-01-29 16:22:31+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL/NTL_1_D.test.cpp
documentation_of: Math/number/phi.hpp
layout: document
redirect_from:
- /library/Math/number/phi.hpp
- /library/Math/number/phi.hpp.html
title: "Euler's Totient Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
---