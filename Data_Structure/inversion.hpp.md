---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Data_Structure/BIT.hpp
    title: Data_Structure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structure/BIT.hpp\"\ntemplate<typename T>\nstruct BIT{\n\
    \  long long N;\n  vector<T>bit;\n  BIT(long long n){\n    N=1;\n    while(N<n){\n\
    \      N*=2;\n    }\n    bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n\
    \    i++;\n    while(i<=N){\n      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n\
    \  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n    return\
    \ ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n};\n#line\
    \ 2 \"Data_Structure/inversion.hpp\"\ntemplate<typename T>\nlong long inversion(vector<T>&a){\n\
    \  int n=a.size();\n  vector<T>b=a;\n  sort(b.begin(),b.end());\n  map<long long,long\
    \ long>mp;\n  for(int i=0;i<n;i++)mp[b[i]]=i+1;\n  for(int i=0;i<n;i++)a[i]=mp[a[i]];\n\
    \  long long ans=0;\n  BIT<long long>c(n);\n  for(int i=0;i<n;i++){\n    ans+=i-c.sum(a[i]);\n\
    \    c.add(a[i],1);\n  }\n  return ans;\n}\n"
  code: "#include\"BIT.hpp\"\ntemplate<typename T>\nlong long inversion(vector<T>&a){\n\
    \  int n=a.size();\n  vector<T>b=a;\n  sort(b.begin(),b.end());\n  map<long long,long\
    \ long>mp;\n  for(int i=0;i<n;i++)mp[b[i]]=i+1;\n  for(int i=0;i<n;i++)a[i]=mp[a[i]];\n\
    \  long long ans=0;\n  BIT<long long>c(n);\n  for(int i=0;i<n;i++){\n    ans+=i-c.sum(a[i]);\n\
    \    c.add(a[i],1);\n  }\n  return ans;\n}"
  dependsOn:
  - Data_Structure/BIT.hpp
  isVerificationFile: false
  path: Data_Structure/inversion.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/inversion.hpp
layout: document
redirect_from:
- /library/Data_Structure/inversion.hpp
- /library/Data_Structure/inversion.hpp.html
title: Data_Structure/inversion.hpp
---
