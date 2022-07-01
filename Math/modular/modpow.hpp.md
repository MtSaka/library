---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/modular/mod_log.hpp
    title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':question:'
    path: Math/modular/mod_sqrt.hpp
    title: "Mod Square Root(\u5E73\u65B9\u5270\u4F59)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_B.test.cpp
    title: test/aoj/NTL/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete-logarithm-mod.test.cpp
    title: test/yosupo/discrete-logarithm-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Mod Pow(\u3079\u304D\u4E57)"
    links: []
  bundledCode: "#line 2 \"Math/modular/modpow.hpp\"\ntemplate<typename T,typename\
    \ S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n\
    \    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\
    \u304D\u4E57)\n*/\n"
  code: "#pragma once\ntemplate<typename T,typename S>\nT modpow(T a,S b,T m){\n \
    \ T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n    a=a*a%m;\n    b>>=1;\n \
    \ }\n  return ret;\n}\n/**\n * @brief Mod Pow(\u3079\u304D\u4E57)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/modular/modpow.hpp
  requiredBy:
  - Math/modular/mod_log.hpp
  - Math/modular/mod_sqrt.hpp
  timestamp: '2022-01-29 16:22:31+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/discrete-logarithm-mod.test.cpp
  - test/aoj/NTL/NTL_1_B.test.cpp
documentation_of: Math/modular/modpow.hpp
layout: document
redirect_from:
- /library/Math/modular/modpow.hpp
- /library/Math/modular/modpow.hpp.html
title: "Mod Pow(\u3079\u304D\u4E57)"
---