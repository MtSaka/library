---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1/ALDS1_1_C_1.test.cpp
    title: test/aoj/ALDS1/ALDS1_1_C_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Prime Determination(\u7D20\u6570\u5224\u5B9A)"
    links: []
  bundledCode: "#line 1 \"Math/number/is_prime.hpp\"\nbool is_prime(long long N){\n\
    \  if(N<2)return 0;\n  if(N==2)return 1;\n  if(N%2==0)return 0;\n  for(long long\
    \ i=3;i*i<=N;i+=2){\n    if(N%i==0)return 0;\n  }\n  return 1;\n}\n/**\n * @brief\
    \ Prime Determination(\u7D20\u6570\u5224\u5B9A)\n*/\n"
  code: "bool is_prime(long long N){\n  if(N<2)return 0;\n  if(N==2)return 1;\n  if(N%2==0)return\
    \ 0;\n  for(long long i=3;i*i<=N;i+=2){\n    if(N%i==0)return 0;\n  }\n  return\
    \ 1;\n}\n/**\n * @brief Prime Determination(\u7D20\u6570\u5224\u5B9A)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/is_prime.hpp
  requiredBy: []
  timestamp: '2022-01-29 16:22:31+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_1_C_1.test.cpp
documentation_of: Math/number/is_prime.hpp
layout: document
redirect_from:
- /library/Math/number/is_prime.hpp
- /library/Math/number/is_prime.hpp.html
title: "Prime Determination(\u7D20\u6570\u5224\u5B9A)"
---
