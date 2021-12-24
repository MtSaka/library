---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_1_B.test.cpp
    title: test/aoj/DSL/DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Weighed Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
    links: []
  bundledCode: "#line 1 \"Data_Structure/weighed_dsu.hpp\"\n/**\n * @brief Weighed\
    \ Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)\n*/ \ntemplate<typename\
    \ T>\nstruct weighed_dsu{\n  vector<int>sz,par;\n  vector<T>diff;\n  weighed_dsu(){}\n\
    \  weighed_dsu(int n,T s=0){\n    sz.resize(n,1);\n    par.resize(n,0);\n    diff.resize(n,s);\n\
    \    for(int i=0;i<n;i++)par[i]=i;\n  }\n  int root(int x){\n    if(x==par[x])return\
    \ x;\n    int r=root(par[x]);\n    diff[x]+=diff[par[x]];\n    return par[x]=r;\n\
    \  }\n  T weight(int x){\n    root(x);\n    return diff[x];\n  }\n  bool same(int\
    \ x,int y){return root(x)==root(y);}\n  int size(int x){return sz[root(x)];}\n\
    \  void merge(int x,int y,T w){\n    w+=weight(x),w-=weight(y);\n    x=root(x),y=root(y);\n\
    \    if(x==y)return ;\n    if(sz[x]<sz[y])swap(x,y),w=-w;\n    sz[x]+=sz[y];\n\
    \    par[y]=x;\n    diff[y]=w;\n  }\n  T dist(int x,int y){\n    return weight(y)-weight(x);\n\
    \  }\n};\n"
  code: "/**\n * @brief Weighed Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)\n\
    */ \ntemplate<typename T>\nstruct weighed_dsu{\n  vector<int>sz,par;\n  vector<T>diff;\n\
    \  weighed_dsu(){}\n  weighed_dsu(int n,T s=0){\n    sz.resize(n,1);\n    par.resize(n,0);\n\
    \    diff.resize(n,s);\n    for(int i=0;i<n;i++)par[i]=i;\n  }\n  int root(int\
    \ x){\n    if(x==par[x])return x;\n    int r=root(par[x]);\n    diff[x]+=diff[par[x]];\n\
    \    return par[x]=r;\n  }\n  T weight(int x){\n    root(x);\n    return diff[x];\n\
    \  }\n  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ sz[root(x)];}\n  void merge(int x,int y,T w){\n    w+=weight(x),w-=weight(y);\n\
    \    x=root(x),y=root(y);\n    if(x==y)return ;\n    if(sz[x]<sz[y])swap(x,y),w=-w;\n\
    \    sz[x]+=sz[y];\n    par[y]=x;\n    diff[y]=w;\n  }\n  T dist(int x,int y){\n\
    \    return weight(y)-weight(x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/weighed_dsu.hpp
  requiredBy: []
  timestamp: '2021-12-23 23:12:39+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_1_B.test.cpp
documentation_of: Data_Structure/weighed_dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/weighed_dsu.hpp
- /library/Data_Structure/weighed_dsu.hpp.html
title: "Weighed Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
---
