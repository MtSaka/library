---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_1_A.test.cpp
    title: test/aoj/DSL/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A.test.cpp
    title: test/aoj/GRL/GRL_2_A.test.cpp
  - icon: ':x:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Disjoint Set Union(Union Find)
    links: []
  bundledCode: "#line 1 \"Data_Structure/dsu.hpp\"\n/**\n * @brief Disjoint Set Union(Union\
    \ Find)\n*/\nstruct dsu{\n  vector<int>p;\n  dsu(int n):p(n,-1){}\n  int root(int\
    \ x){return p[x]<0?x:p[x]=root(p[x]);}\n  bool same(int x,int y){return root(x)==root(y);}\n\
    \  int size(int x){return -p[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n\
    \    if(x==y)return;\n    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n  }\n\
    };\n"
  code: "/**\n * @brief Disjoint Set Union(Union Find)\n*/\nstruct dsu{\n  vector<int>p;\n\
    \  dsu(int n):p(n,-1){}\n  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}\n\
    \  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ -p[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return;\n\
    \    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dsu.hpp
  requiredBy:
  - Graph/kruskal.hpp
  timestamp: '2022-01-02 20:26:45+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL/DSL_1_A.test.cpp
  - test/aoj/GRL/GRL_2_A.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: Data_Structure/dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/dsu.hpp
- /library/Data_Structure/dsu.hpp.html
title: Disjoint Set Union(Union Find)
---
