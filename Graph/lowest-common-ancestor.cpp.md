---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-5-c.test.cpp
    title: test/verify/aoj-grl-5-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-lca-3.test.cpp
    title: test/verify/yosupo-lca-3.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/lowest-common-ancestor.cpp\"\nstruct LCA{\n  int lg=0;\n\
    \  vector<int>dep;\n  const vector<vector<int>>&g;\n  vector<vector<int>>table;\n\
    \  LCA(const vector<vector<int>>&g):g(g),dep(g.size()){\n    while((1<<lg)<g.size())lg++;\n\
    \    table.assign(lg,vector<int>(g.size(),-1));\n    build();\n  }\n  void dfs(int\
    \ idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n    for(auto &to:g[idx]){\n\
    \      if(to!=par)dfs(to,idx,d+1);\n    }\n  }\n  void build(){\n    dfs(0,-1,0);\n\
    \    for(int k=0;k+1<lg;k++){\n      for(int i=0;i<table[k].size();i++){\n   \
    \     if(table[k][i]==-1)table[k+1][i]=-1;\n        else table[k+1][i]=table[k][table[k][i]];\n\
    \      }\n    }\n  }\n  int query(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n\
    \    for(int i=lg-1;i>=0;i--){\n      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];\n\
    \    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n      if(table[i][u]!=table[i][v]){\n\
    \        u=table[i][u];\n        v=table[i][v];\n      }\n    }\n    return table[0][u];\n\
    \  }\n};\n"
  code: "struct LCA{\n  int lg=0;\n  vector<int>dep;\n  const vector<vector<int>>&g;\n\
    \  vector<vector<int>>table;\n  LCA(const vector<vector<int>>&g):g(g),dep(g.size()){\n\
    \    while((1<<lg)<g.size())lg++;\n    table.assign(lg,vector<int>(g.size(),-1));\n\
    \    build();\n  }\n  void dfs(int idx,int par,int d){\n    table[0][idx]=par;\n\
    \    dep[idx]=d;\n    for(auto &to:g[idx]){\n      if(to!=par)dfs(to,idx,d+1);\n\
    \    }\n  }\n  void build(){\n    dfs(0,-1,0);\n    for(int k=0;k+1<lg;k++){\n\
    \      for(int i=0;i<table[k].size();i++){\n        if(table[k][i]==-1)table[k+1][i]=-1;\n\
    \        else table[k+1][i]=table[k][table[k][i]];\n      }\n    }\n  }\n  int\
    \ query(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n    for(int i=lg-1;i>=0;i--){\n\
    \      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];\n    }\n    if(u==v)return u;\n\
    \    for(int i=lg-1;i>=0;i--){\n      if(table[i][u]!=table[i][v]){\n        u=table[i][u];\n\
    \        v=table[i][v];\n      }\n    }\n    return table[0][u];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/lowest-common-ancestor.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-grl-5-c.test.cpp
  - test/verify/yosupo-lca-3.test.cpp
documentation_of: Graph/lowest-common-ancestor.cpp
layout: document
redirect_from:
- /library/Graph/lowest-common-ancestor.cpp
- /library/Graph/lowest-common-ancestor.cpp.html
title: Graph/lowest-common-ancestor.cpp
---
