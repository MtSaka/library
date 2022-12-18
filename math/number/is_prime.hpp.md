---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_1_C_1.test.cpp
    title: test/aoj/ALDS1/ALDS1_1_C_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Prime Determination(\u7D20\u6570\u5224\u5B9A)"
    links: []
  bundledCode: "#line 1 \"math/number/is_prime.hpp\"\nbool is_prime(long long N){\n\
    \  if(N<2)return 0;\n  if(N==2)return 1;\n  if(N%2==0)return 0;\n  for(long long\
    \ i=3;i*i<=N;i+=2){\n    if(N%i==0)return 0;\n  }\n  return 1;\n}\n/**\n * @brief\
    \ Prime Determination(\u7D20\u6570\u5224\u5B9A)\n*/\n"
  code: "bool is_prime(long long N){\n  if(N<2)return 0;\n  if(N==2)return 1;\n  if(N%2==0)return\
    \ 0;\n  for(long long i=3;i*i<=N;i+=2){\n    if(N%i==0)return 0;\n  }\n  return\
    \ 1;\n}\n/**\n * @brief Prime Determination(\u7D20\u6570\u5224\u5B9A)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/number/is_prime.hpp
  requiredBy: []
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_1_C_1.test.cpp
documentation_of: math/number/is_prime.hpp
layout: document
redirect_from:
- /library/math/number/is_prime.hpp
- /library/math/number/is_prime.hpp.html
title: "Prime Determination(\u7D20\u6570\u5224\u5B9A)"
---
