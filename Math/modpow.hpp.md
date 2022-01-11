---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_B.test.cpp
    title: test/aoj/NTL/NTL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Mod Pow(\u3079\u304D\u4E57)"
    links: []
  bundledCode: "#line 1 \"Math/modpow.hpp\"\ntemplate<typename T,typename S>\nT modpow(T\
    \ a,S b,T m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n\
    \    b>>=1;\n  }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\u304D\u4E57\
    )\n*/\n"
  code: "template<typename T,typename S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n\
    \    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n\
    \ * @brief Mod Pow(\u3079\u304D\u4E57)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/modpow.hpp
  requiredBy: []
  timestamp: '2022-01-11 21:13:55+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL/NTL_1_B.test.cpp
documentation_of: Math/modpow.hpp
layout: document
redirect_from:
- /library/Math/modpow.hpp
- /library/Math/modpow.hpp.html
title: "Mod Pow(\u3079\u304D\u4E57)"
---
