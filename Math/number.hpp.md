---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/number.hpp\"\nlong long digsum(long long n){\n  long\
    \ long ans=0;\n  while(n){\n    ans+=n%10;\n    n/=10;\n  }\n  return ans;\n}\n\
    long long gcd(long long a,long long b){return (b?gcd(b,a%b):a);}\nlong long lcm(long\
    \ long a,long long b){return a/gcd(a,b)*b;}\n"
  code: "long long digsum(long long n){\n  long long ans=0;\n  while(n){\n    ans+=n%10;\n\
    \    n/=10;\n  }\n  return ans;\n}\nlong long gcd(long long a,long long b){return\
    \ (b?gcd(b,a%b):a);}\nlong long lcm(long long a,long long b){return a/gcd(a,b)*b;}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number.hpp
layout: document
redirect_from:
- /library/Math/number.hpp
- /library/Math/number.hpp.html
title: Math/number.hpp
---
