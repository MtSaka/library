---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/convolution/lcm_convolution.hpp\"\ntemplate<typename\
    \ T>\nvector<T>lcm_convolution(vector<T>a,vector<T>b){\n  const int n=a.size();\n\
    \  vector<bool>sieve(n,true);\n  for(int p=2;p<n;p++)if(sieve[p]){\n    for(int\
    \ i=1;i*p<n;i++)a[i*p]+=a[i],sieve[i*p]=false;\n    sieve[p]=true;\n  }\n  for(int\
    \ p=2;p<n;p++)if(sieve[p])for(int i=1;i*p<n;i++)b[i*p]+=b[i];\n  for(int i=0;i<n;i++)a[i]*=b[i];\n\
    \  for(int p=2;p<n;p++)if(sieve[p])for(int i=(n-1)/p;i>0;i--)a[i*p]-=a[i];\n \
    \ return a;\n}\n"
  code: "#pragma once\ntemplate<typename T>\nvector<T>lcm_convolution(vector<T>a,vector<T>b){\n\
    \  const int n=a.size();\n  vector<bool>sieve(n,true);\n  for(int p=2;p<n;p++)if(sieve[p]){\n\
    \    for(int i=1;i*p<n;i++)a[i*p]+=a[i],sieve[i*p]=false;\n    sieve[p]=true;\n\
    \  }\n  for(int p=2;p<n;p++)if(sieve[p])for(int i=1;i*p<n;i++)b[i*p]+=b[i];\n\
    \  for(int i=0;i<n;i++)a[i]*=b[i];\n  for(int p=2;p<n;p++)if(sieve[p])for(int\
    \ i=(n-1)/p;i>0;i--)a[i*p]-=a[i];\n  return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2022-07-18 23:04:26+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lcm_convolution.test.cpp
documentation_of: Math/convolution/lcm_convolution.hpp
layout: document
redirect_from:
- /library/Math/convolution/lcm_convolution.hpp
- /library/Math/convolution/lcm_convolution.hpp.html
title: Math/convolution/lcm_convolution.hpp
---
