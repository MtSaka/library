---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/mst/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_1_A.test.cpp
    title: test/aoj/DSL/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A.test.cpp
    title: test/aoj/GRL/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Disjoint Set Union(Union Find)
    links: []
  bundledCode: "#line 2 \"Data_Structure/dsu.hpp\"\nstruct dsu{\n  private:\n  vector<int>p;\n\
    \  public:\n  dsu(int n):p(n,-1){}\n  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}\n\
    \  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ -p[root(x)];}\n  int merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return\
    \ x;\n    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n    return x;\n  }\n\
    \  vector<vector<int>>groups(){\n    const int n=p.size();\n    vector<int>leader(n),group_size(n);\n\
    \    for(int i=0;i<n;i++){\n      leader[i]=root(i);\n      group_size[leader[i]]++;\n\
    \    }\n    vector<vector<int>>result(n);\n    for(int i=0;i<n;i++)result[i].reserve(group_size[i]);\n\
    \    for(int i=0;i<n;i++)result[leader[i]].push_back(i);\n    result.erase(remove_if(result.begin(),result.end(),[](const\
    \ vector<int>&v){return v.empty();}),result.end());\n    return result;\n  }\n\
    };\n/**\n * @brief Disjoint Set Union(Union Find)\n*/\n"
  code: "#pragma once\nstruct dsu{\n  private:\n  vector<int>p;\n  public:\n  dsu(int\
    \ n):p(n,-1){}\n  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}\n  bool same(int\
    \ x,int y){return root(x)==root(y);}\n  int size(int x){return -p[root(x)];}\n\
    \  int merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return x;\n\
    \    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n    return x;\n  }\n  vector<vector<int>>groups(){\n\
    \    const int n=p.size();\n    vector<int>leader(n),group_size(n);\n    for(int\
    \ i=0;i<n;i++){\n      leader[i]=root(i);\n      group_size[leader[i]]++;\n  \
    \  }\n    vector<vector<int>>result(n);\n    for(int i=0;i<n;i++)result[i].reserve(group_size[i]);\n\
    \    for(int i=0;i<n;i++)result[leader[i]].push_back(i);\n    result.erase(remove_if(result.begin(),result.end(),[](const\
    \ vector<int>&v){return v.empty();}),result.end());\n    return result;\n  }\n\
    };\n/**\n * @brief Disjoint Set Union(Union Find)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dsu.hpp
  requiredBy:
  - Graph/mst/kruskal.hpp
  timestamp: '2022-06-01 18:39:17+01:00'
  verificationStatus: LIBRARY_ALL_AC
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
