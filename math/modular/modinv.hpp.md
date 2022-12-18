---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Mod Inv(\u9006\u5143)"
    links: []
  bundledCode: "#line 2 \"math/modular/modinv.hpp\"\ntemplate<typename T>\nT modinv(T\
    \ a,T m){\n  T b=m,c=1,d=0,t;\n  while(b){\n    t=a/b;\n    a-=t*b;swap(a,b);\n\
    \    c-=t*d;swap(c,d);\n  }\n  c%=m;\n  if(c<0)c+=m;\n  return c;\n}\n/**\n *\
    \ @brief Mod Inv(\u9006\u5143)\n*/\n"
  code: "#pragma once\ntemplate<typename T>\nT modinv(T a,T m){\n  T b=m,c=1,d=0,t;\n\
    \  while(b){\n    t=a/b;\n    a-=t*b;swap(a,b);\n    c-=t*d;swap(c,d);\n  }\n\
    \  c%=m;\n  if(c<0)c+=m;\n  return c;\n}\n/**\n * @brief Mod Inv(\u9006\u5143\
    )\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/modular/modinv.hpp
  requiredBy: []
  timestamp: '2022-12-18 22:43:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modular/modinv.hpp
layout: document
redirect_from:
- /library/math/modular/modinv.hpp
- /library/math/modular/modinv.hpp.html
title: "Mod Inv(\u9006\u5143)"
---
