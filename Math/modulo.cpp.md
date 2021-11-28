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
  bundledCode: "#line 1 \"Math/modulo.cpp\"\nlong long modpow(long long a,long long\
    \ n,long long m){\n  long long ans=1;\n  while(n>0){\n    if(n&1)ans=ans*a%m;\n\
    \    a=a*a%m;\n    n>>=1;\n  }\n  return ans;\n}\nlong long modinv(long long a,long\
    \ long m){\n  long long b=m,c=1,d=0;\n  while(b){\n    long long t=a/b;\n    a-=t*b;swap(a,b);\n\
    \    c-=t*d;swap(c,d);\n  }\n  c%=m;\n  if(c<0)c+=m;\n  return c;\n}\n"
  code: "long long modpow(long long a,long long n,long long m){\n  long long ans=1;\n\
    \  while(n>0){\n    if(n&1)ans=ans*a%m;\n    a=a*a%m;\n    n>>=1;\n  }\n  return\
    \ ans;\n}\nlong long modinv(long long a,long long m){\n  long long b=m,c=1,d=0;\n\
    \  while(b){\n    long long t=a/b;\n    a-=t*b;swap(a,b);\n    c-=t*d;swap(c,d);\n\
    \  }\n  c%=m;\n  if(c<0)c+=m;\n  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/modulo.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/modulo.cpp
layout: document
redirect_from:
- /library/Math/modulo.cpp
- /library/Math/modulo.cpp.html
title: Math/modulo.cpp
---