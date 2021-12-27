---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_1_A.test.cpp
    title: test/aoj/DSL/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Disjoint Set Union(Union Find)
    links: []
  bundledCode: "#line 1 \"Data_Structure/dsu.hpp\"\n/**\n * @brief Disjoint Set Union(Union\
    \ Find)\n*/\nstruct dsu{\n  vector<int>sz,par;\n  dsu(){}\n  dsu(int n){\n   \
    \ sz.resize(n,1);\n    par.resize(n,0);\n    for(int i=0;i<n;i++)par[i]=i;\n \
    \ }\n  int root(int x){\n    if(x==par[x])return x;\n    return par[x]=root(par[x]);\n\
    \  }\n  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return\
    \ ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n    }\n    else{\n\
    \      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};\n"
  code: "/**\n * @brief Disjoint Set Union(Union Find)\n*/\nstruct dsu{\n  vector<int>sz,par;\n\
    \  dsu(){}\n  dsu(int n){\n    sz.resize(n,1);\n    par.resize(n,0);\n    for(int\
    \ i=0;i<n;i++)par[i]=i;\n  }\n  int root(int x){\n    if(x==par[x])return x;\n\
    \    return par[x]=root(par[x]);\n  }\n  bool same(int x,int y){return root(x)==root(y);}\n\
    \  int size(int x){return sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n\
    \    if(x==y)return ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n\
    \    }\n    else{\n      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dsu.hpp
  requiredBy:
  - Graph/kruskal.hpp
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_1_A.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: Data_Structure/dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/dsu.hpp
- /library/Data_Structure/dsu.hpp.html
title: Disjoint Set Union(Union Find)
---
