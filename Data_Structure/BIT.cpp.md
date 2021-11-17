---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Data_Structure/inversion.cpp
    title: Data_Structure/inversion.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structure/BIT.cpp\"\ntemplate<typename T>\nstruct BIT{\n\
    \  long long N;\n  vector<T>bit;\n  BIT(long long n){\n    N=1;\n    while(N<n){\n\
    \      N*=2;\n    }\n    bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n\
    \    i++;\n    while(i<=N){\n      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n\
    \  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n    return\
    \ ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n};\n"
  code: "template<typename T>\nstruct BIT{\n  long long N;\n  vector<T>bit;\n  BIT(long\
    \ long n){\n    N=1;\n    while(N<n){\n      N*=2;\n    }\n    bit=vector<T>(N+1,0);\n\
    \  }\n  void add(int i,T x){\n    i++;\n    while(i<=N){\n      bit[i]+=x;\n \
    \     i+=i&-i;    \n    }\n  }\n  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n\
    \    return ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/BIT.cpp
  requiredBy:
  - Data_Structure/inversion.cpp
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/BIT.cpp
layout: document
redirect_from:
- /library/Data_Structure/BIT.cpp
- /library/Data_Structure/BIT.cpp.html
title: Data_Structure/BIT.cpp
---
