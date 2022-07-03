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
    document_title: "Weighted Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
    links: []
  bundledCode: "#line 2 \"Data_Structure/weighted_dsu.hpp\"\ntemplate<typename T>\n\
    struct weighted_dsu{\n  vector<int>p;vector<T>diff;\n  weighted_dsu(){}\n  weighted_dsu(int\
    \ n,T s=0):p(n,-1),diff(n,s){}\n  int root(int x){\n    if(p[x]<0)return x;\n\
    \    int r=root(p[x]);\n    diff[x]+=diff[p[x]];\n    return p[x]=r;\n  }\n  T\
    \ weight(int x){\n    root(x);\n    return diff[x];\n  }\n  bool same(int x,int\
    \ y){return root(x)==root(y);}\n  int size(int x){return -p[root(x)];}\n  void\
    \ merge(int x,int y,T w){\n    w+=weight(x),w-=weight(y);\n    x=root(x),y=root(y);\n\
    \    if(x==y)return ;\n    if(p[x]>p[y])swap(x,y),w=-w;\n    p[x]+=p[y];\n   \
    \ p[y]=x;\n    diff[y]=w;\n  }\n  T dist(int x,int y){\n    return weight(y)-weight(x);\n\
    \  }\n};\n/**\n * @brief Weighted Disjoint Set Union(\u91CD\u307F\u4ED8\u304D\
    Union Find)\n*/ \n"
  code: "#pragma once\ntemplate<typename T>\nstruct weighted_dsu{\n  vector<int>p;vector<T>diff;\n\
    \  weighted_dsu(){}\n  weighted_dsu(int n,T s=0):p(n,-1),diff(n,s){}\n  int root(int\
    \ x){\n    if(p[x]<0)return x;\n    int r=root(p[x]);\n    diff[x]+=diff[p[x]];\n\
    \    return p[x]=r;\n  }\n  T weight(int x){\n    root(x);\n    return diff[x];\n\
    \  }\n  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ -p[root(x)];}\n  void merge(int x,int y,T w){\n    w+=weight(x),w-=weight(y);\n\
    \    x=root(x),y=root(y);\n    if(x==y)return ;\n    if(p[x]>p[y])swap(x,y),w=-w;\n\
    \    p[x]+=p[y];\n    p[y]=x;\n    diff[y]=w;\n  }\n  T dist(int x,int y){\n \
    \   return weight(y)-weight(x);\n  }\n};\n/**\n * @brief Weighted Disjoint Set\
    \ Union(\u91CD\u307F\u4ED8\u304DUnion Find)\n*/ "
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/weighted_dsu.hpp
  requiredBy: []
  timestamp: '2022-01-21 16:32:03+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_1_B.test.cpp
documentation_of: Data_Structure/weighted_dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/weighted_dsu.hpp
- /library/Data_Structure/weighted_dsu.hpp.html
title: "Weighted Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
---