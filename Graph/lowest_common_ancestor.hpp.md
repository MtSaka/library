---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
    links: []
  bundledCode: "#line 1 \"Graph/lowest_common_ancestor.hpp\"\n/**\n * @brief Lowest\
    \ Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)\n*/\n#line 1 \"Graph/graph_template.hpp\"\
    \n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n*/\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n\
    \  int idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n\
    \  vector<vector<Edge>>g;\n  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n\
    \  size_t size()const{return g.size();}\n  size_t edge_size()const{return es;}\n\
    \  void add_directed_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n\
    \  }\n  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/lowest_common_ancestor.hpp\"\
    \ntemplate<typename T>\nstruct LCA{\n  int lg=0;\n  vector<int>dep;\n  const Graph<T>&g;\n\
    \  vector<vector<int>>table;\n  LCA(int n):g(n),dep(n){\n    g.read(n-1);\n  \
    \  while((1<<lg)<n)lg++;\n    table.assign(lg,vector<int>(n,-1));\n    build();\n\
    \  }\n  LCA(const Graph<T>&g):g(g),dep(g.size()){\n    while((1<<lg)<g.size())lg++;\n\
    \    table.assign(lg,vector<int>(g.size(),-1));\n    build();\n  }\n  void dfs(int\
    \ idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n    for(auto &e:g[idx]){\n\
    \      if(e!=par)dfs(e,idx,d+1);\n    }\n  }\n  void build(){\n    dfs(0,-1,0);\n\
    \    for(int k=0;k+1<lg;k++){\n      for(int i=0;i<table[k].size();i++){\n   \
    \     if(table[k][i]==-1)table[k+1][i]=-1;\n        else table[k+1][i]=table[k][table[k][i]];\n\
    \      }\n    }\n  }\n  int query(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n\
    \    for(int i=lg-1;i>=0;i--){\n      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];\n\
    \    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n      if(table[i][u]!=table[i][v]){\n\
    \        u=table[i][u];\n        v=table[i][v];\n      }\n    }\n    return table[0][u];\n\
    \  }\n};\n"
  code: "/**\n * @brief Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148\
    )\n*/\n#include\"graph_template.hpp\"\ntemplate<typename T>\nstruct LCA{\n  int\
    \ lg=0;\n  vector<int>dep;\n  const Graph<T>&g;\n  vector<vector<int>>table;\n\
    \  LCA(int n):g(n),dep(n){\n    g.read(n-1);\n    while((1<<lg)<n)lg++;\n    table.assign(lg,vector<int>(n,-1));\n\
    \    build();\n  }\n  LCA(const Graph<T>&g):g(g),dep(g.size()){\n    while((1<<lg)<g.size())lg++;\n\
    \    table.assign(lg,vector<int>(g.size(),-1));\n    build();\n  }\n  void dfs(int\
    \ idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n    for(auto &e:g[idx]){\n\
    \      if(e!=par)dfs(e,idx,d+1);\n    }\n  }\n  void build(){\n    dfs(0,-1,0);\n\
    \    for(int k=0;k+1<lg;k++){\n      for(int i=0;i<table[k].size();i++){\n   \
    \     if(table[k][i]==-1)table[k+1][i]=-1;\n        else table[k+1][i]=table[k][table[k][i]];\n\
    \      }\n    }\n  }\n  int query(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n\
    \    for(int i=lg-1;i>=0;i--){\n      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];\n\
    \    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n      if(table[i][u]!=table[i][v]){\n\
    \        u=table[i][u];\n        v=table[i][v];\n      }\n    }\n    return table[0][u];\n\
    \  }\n};"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/lca.test.cpp
documentation_of: Graph/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/Graph/lowest_common_ancestor.hpp
- /library/Graph/lowest_common_ancestor.hpp.html
title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
