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
  bundledCode: "#line 1 \"Math/number.cpp\"\nlong long digsum(long long n){\n  long\
    \ long ans=0;\n  while(n){\n    ans+=n%10;\n    n/=10;\n  }\n  return ans;\n}\n\
    long long gcd(long long a,long long b){return (b?gcd(b,a%b):a);}\nlong long lcm(long\
    \ long a,long long b){return a/gcd(a,b)*b;}\n"
  code: "long long digsum(long long n){\n  long long ans=0;\n  while(n){\n    ans+=n%10;\n\
    \    n/=10;\n  }\n  return ans;\n}\nlong long gcd(long long a,long long b){return\
    \ (b?gcd(b,a%b):a);}\nlong long lcm(long long a,long long b){return a/gcd(a,b)*b;}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number.cpp
layout: document
redirect_from:
- /library/Math/number.cpp
- /library/Math/number.cpp.html
title: Math/number.cpp
---
