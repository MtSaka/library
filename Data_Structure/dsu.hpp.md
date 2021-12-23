---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structure/dsu.hpp\"\nstruct dsu{\n  vector<int>sz,par;\n\
    \  dsu(){}\n  dsu(int n){\n    sz.resize(n,1);\n    par.resize(n,0);\n    for(int\
    \ i=0;i<n;i++)par[i]=i;\n  }\n  int root(int x){\n    if(x==par[x])return x;\n\
    \    return par[x]=root(par[x]);\n  }\n  bool same(int x,int y){return root(x)==root(y);}\n\
    \  int size(int x){return sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n\
    \    if(x==y)return ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n\
    \    }\n    else{\n      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};\n"
  code: "struct dsu{\n  vector<int>sz,par;\n  dsu(){}\n  dsu(int n){\n    sz.resize(n,1);\n\
    \    par.resize(n,0);\n    for(int i=0;i<n;i++)par[i]=i;\n  }\n  int root(int\
    \ x){\n    if(x==par[x])return x;\n    return par[x]=root(par[x]);\n  }\n  bool\
    \ same(int x,int y){return root(x)==root(y);}\n  int size(int x){return sz[root(x)];}\n\
    \  void merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return ;\n\
    \    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n    }\n    else{\n\
    \      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dsu.hpp
  requiredBy:
  - Graph/kruskal.hpp
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/dsu.hpp
- /library/Data_Structure/dsu.hpp.html
title: Data_Structure/dsu.hpp
---
