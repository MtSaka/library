---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/BIT.hpp
    title: Binary Indexed Tree(BIT)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Inversion Number(\u8EE2\u5012\u6570)"
    links: []
  bundledCode: "#line 1 \"Data_Structure/inversion.hpp\"\n/**\n * @brief Inversion\
    \ Number(\u8EE2\u5012\u6570)\n*/\n#line 1 \"Data_Structure/BIT.hpp\"\n/**\n *\
    \ @brief Binary Indexed Tree(BIT)\n*/\ntemplate<typename T>\nstruct BIT{\n  long\
    \ long N;\n  vector<T>bit;\n  BIT(long long n){\n    N=1;\n    while(N<n){\n \
    \     N*=2;\n    }\n    bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n \
    \   i++;\n    while(i<=N){\n      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n\
    \  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n    return\
    \ ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n};\n#line\
    \ 5 \"Data_Structure/inversion.hpp\"\ntemplate<typename T>\nlong long inversion(vector<T>&a){\n\
    \  int n=a.size();\n  vector<T>b=a;\n  sort(b.begin(),b.end());\n  map<long long,long\
    \ long>mp;\n  for(int i=0;i<n;i++)mp[b[i]]=i+1;\n  for(int i=0;i<n;i++)a[i]=mp[a[i]];\n\
    \  long long ans=0;\n  BIT<long long>c(n);\n  for(int i=0;i<n;i++){\n    ans+=i-c.sum(a[i]);\n\
    \    c.add(a[i],1);\n  }\n  return ans;\n}\n"
  code: "/**\n * @brief Inversion Number(\u8EE2\u5012\u6570)\n*/\n#include\"BIT.hpp\"\
    \ntemplate<typename T>\nlong long inversion(vector<T>&a){\n  int n=a.size();\n\
    \  vector<T>b=a;\n  sort(b.begin(),b.end());\n  map<long long,long long>mp;\n\
    \  for(int i=0;i<n;i++)mp[b[i]]=i+1;\n  for(int i=0;i<n;i++)a[i]=mp[a[i]];\n \
    \ long long ans=0;\n  BIT<long long>c(n);\n  for(int i=0;i<n;i++){\n    ans+=i-c.sum(a[i]);\n\
    \    c.add(a[i],1);\n  }\n  return ans;\n}"
  dependsOn:
  - Data_Structure/BIT.hpp
  isVerificationFile: false
  path: Data_Structure/inversion.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_5_D.test.cpp
documentation_of: Data_Structure/inversion.hpp
layout: document
redirect_from:
- /library/Data_Structure/inversion.hpp
- /library/Data_Structure/inversion.hpp.html
title: "Inversion Number(\u8EE2\u5012\u6570)"
---
