---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Prime Determination(\u7D20\u6570\u5224\u5B9A)"
    links: []
  bundledCode: "#line 1 \"Math/is_prime.hpp\"\n/**\n * @brief Prime Determination(\u7D20\
    \u6570\u5224\u5B9A)\n*/\nbool is_prime(long long N){\n  if(N<2)return 0;\n  if(N==2)return\
    \ 1;\n  if(N%2==0)return 0;\n  for(long long i=3;i*i<=N;i+=2){\n    if(N%i==0)return\
    \ 0;\n  }\n  return 1;\n}\n"
  code: "/**\n * @brief Prime Determination(\u7D20\u6570\u5224\u5B9A)\n*/\nbool is_prime(long\
    \ long N){\n  if(N<2)return 0;\n  if(N==2)return 1;\n  if(N%2==0)return 0;\n \
    \ for(long long i=3;i*i<=N;i+=2){\n    if(N%i==0)return 0;\n  }\n  return 1;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Math/is_prime.hpp
  requiredBy: []
  timestamp: '2021-12-23 23:12:39+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/is_prime.hpp
layout: document
redirect_from:
- /library/Math/is_prime.hpp
- /library/Math/is_prime.hpp.html
title: "Prime Determination(\u7D20\u6570\u5224\u5B9A)"
---
