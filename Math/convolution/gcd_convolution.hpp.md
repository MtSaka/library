---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: GCD Convolution
    links: []
  bundledCode: "#line 2 \"Math/convolution/gcd_convolution.hpp\"\ntemplate<typename\
    \ T>\nvector<T>gcd_convolution(vector<T>a,vector<T>b){\n  const int n=a.size();\n\
    \  vector<bool>sieve(n,true);\n  for(int p=2;p<n;p++)if(sieve[p]){\n    for(int\
    \ i=(n-1)/p;i>0;i--)a[i]+=a[i*p],sieve[i*p]=false;\n    sieve[p]=1;\n  }\n  for(int\
    \ p=2;p<n;p++)if(sieve[p])for(int i=(n-1)/p;i>0;i--)b[i]+=b[i*p];\n  for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \  for(int p=2;p<n;p++)if(sieve[p]){\n    for(int i=1;i*p<n;i++)a[i]-=a[i*p];\n\
    \  }\n  return a;\n}\n/**\n * @brief GCD Convolution\n*/\n"
  code: "#pragma once\ntemplate<typename T>\nvector<T>gcd_convolution(vector<T>a,vector<T>b){\n\
    \  const int n=a.size();\n  vector<bool>sieve(n,true);\n  for(int p=2;p<n;p++)if(sieve[p]){\n\
    \    for(int i=(n-1)/p;i>0;i--)a[i]+=a[i*p],sieve[i*p]=false;\n    sieve[p]=1;\n\
    \  }\n  for(int p=2;p<n;p++)if(sieve[p])for(int i=(n-1)/p;i>0;i--)b[i]+=b[i*p];\n\
    \  for(int i=0;i<n;i++)a[i]*=b[i];\n  for(int p=2;p<n;p++)if(sieve[p]){\n    for(int\
    \ i=1;i*p<n;i++)a[i]-=a[i*p];\n  }\n  return a;\n}\n/**\n * @brief GCD Convolution\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Math/convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2022-07-18 23:14:31+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/gcd_convolution.test.cpp
documentation_of: Math/convolution/gcd_convolution.hpp
layout: document
redirect_from:
- /library/Math/convolution/gcd_convolution.hpp
- /library/Math/convolution/gcd_convolution.hpp.html
title: GCD Convolution
---
