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
  bundledCode: "#line 1 \"Data_Structure/dsu.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nstruct dsu{\n  vector<int>sz,par;\n  dsu(){}\n  dsu(int n){\n\
    \    sz.resize(n,1);\n    par.resize(n,0);\n    for(int i=0;i<n;i++)par[i]=i;\n\
    \  }\n  int root(int x){\n    if(x==par[x])return x;\n    return par[x]=root(par[x]);\n\
    \  }\n  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return\
    \ ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n    }\n    else{\n\
    \      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\nstruct dsu{\n  vector<int>sz,par;\n\
    \  dsu(){}\n  dsu(int n){\n    sz.resize(n,1);\n    par.resize(n,0);\n    for(int\
    \ i=0;i<n;i++)par[i]=i;\n  }\n  int root(int x){\n    if(x==par[x])return x;\n\
    \    return par[x]=root(par[x]);\n  }\n  bool same(int x,int y){return root(x)==root(y);}\n\
    \  int size(int x){return sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n\
    \    if(x==y)return ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n\
    \    }\n    else{\n      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dsu.cpp
  requiredBy: []
  timestamp: '2021-08-22 21:38:50+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/dsu.cpp
layout: document
redirect_from:
- /library/Data_Structure/dsu.cpp
- /library/Data_Structure/dsu.cpp.html
title: Data_Structure/dsu.cpp
---
