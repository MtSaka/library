---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/graph_template.hpp
    title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_5_C_1.test.cpp
    title: test/aoj/GRL/GRL_5_C_1.test.cpp
  - icon: ':x:'
    path: test/yosupo/lca1.test.cpp
    title: test/yosupo/lca1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\
      \u5148)"
    links: []
  bundledCode: "#line 2 \"Graph/graph_template.hpp\"\ntemplate<typename T=int>\nstruct\
    \ edge{\n  int from,to;\n  T cost;\n  int idx;\n  edge(){}\n  edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n  bool operator<(const edge&e)const{return cost<e.cost;}\n\
    };\ntemplate<typename T=int>\nusing edges=vector<edge<T>>;\ntemplate<typename\
    \ T=int>\nstruct graph{\n  vector<vector<edge<T>>>g;\n  int es;\n  graph(){}\n\
    \  explicit graph(int n):g(n),es(0){}\n  size_t size()const{return g.size();}\n\
    \  size_t edge_size()const{return es;}\n  void add_edge(int from,int to,T cost=1,bool\
    \ direct=false){\n    g[from].emplace_back(from,to,cost,es);\n    if(!direct)g[to].emplace_back(to,from,cost,es);\n\
    \    es++;\n  }\n  void add_edge(int from,int to,bool direct=false){\n    g[from].emplace_back(from,to,1,es);\n\
    \    if(!direct)g[to].emplace_back(to,from,1,es);\n  }\n  inline vector<edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighted=false,bool direct=false){\n\
    \    int a,b;\n    T c=T(1);\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n  \
    \    a+=padding;\n      b+=padding;\n      if(weighted)cin>>c;\n      add_edge(a,b,c,direct);\n\
    \    }\n  }\n};\nstruct unweighted_edge{\n  template<class... Args>unweighted_edge(const\
    \ Args&...){}\n  operator int()const{return 1;}\n};\nistream &operator>>(istream&is,unweighted_edge&c){c=unweighted_edge();return\
    \ is;}\nusing unweighted_graph=graph<unweighted_edge>;\n/**\n * @brief graph Template(\u30B0\
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 3 \"Graph/tree/doubling_lowest_common_ancestor.hpp\"\
    \ntemplate<typename T=unweighted_edge>\nstruct Doubling_LCA:graph<T>{\n  using\
    \ graph<T>::g;\n  const int lg;\n  vector<int>dep;\n  vector<T>sum;\n  vector<vector<int>>table;\n\
    \  Doubling_LCA(int n):graph<T>(n),lg(32-__builtin_clz(n)){}\n  Doubling_LCA(const\
    \ graph<T>&g):graph<T>(g),lg(32-__builtin_clz(g.size())){}\n  void build(int root=0){\n\
    \    dep.assign(g.size(),0);\n    sum.assign(g.size(),0);\n    table.assign(lg,vector<int>(g.size(),-1));\n\
    \    dfs(root,-1,0);\n    for(int k=0;k+1<lg;k++){\n      for(int i=0;i<(int)table[k].size();i++){\n\
    \        if(table[k][i]==-1)table[k+1][i]=-1;\n        else table[k+1][i]=table[k][table[k][i]];\n\
    \      }\n    }\n  }\n  int lca(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n\
    \    int k=dep[v]-dep[u];\n    if(dep[v]<k)return -1;\n    for(int i=lg-1;i>=0;i--){\n\
    \      if((k>>i)&1)v=table[i][v];\n    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n\
    \      if(table[i][u]!=table[i][v]){\n        u=table[i][u];\n        v=table[i][v];\n\
    \      }\n    }\n    return table[0][u];\n  }\n  T dist(int u,int v){return sum[u]+sum[v]-2*sum[lca(u,v)];}\n\
    \  private:\n  void dfs(int idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n\
    \    for(auto &e:g[idx])if(e!=par){\n      sum[e]=sum[idx]+e.cost;\n      dfs(e,idx,d+1);\n\
    \    }\n  }\n};\n/**\n * @brief Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n*/\n"
  code: "#pragma once\n#include\"../graph_template.hpp\"\ntemplate<typename T=unweighted_edge>\n\
    struct Doubling_LCA:graph<T>{\n  using graph<T>::g;\n  const int lg;\n  vector<int>dep;\n\
    \  vector<T>sum;\n  vector<vector<int>>table;\n  Doubling_LCA(int n):graph<T>(n),lg(32-__builtin_clz(n)){}\n\
    \  Doubling_LCA(const graph<T>&g):graph<T>(g),lg(32-__builtin_clz(g.size())){}\n\
    \  void build(int root=0){\n    dep.assign(g.size(),0);\n    sum.assign(g.size(),0);\n\
    \    table.assign(lg,vector<int>(g.size(),-1));\n    dfs(root,-1,0);\n    for(int\
    \ k=0;k+1<lg;k++){\n      for(int i=0;i<(int)table[k].size();i++){\n        if(table[k][i]==-1)table[k+1][i]=-1;\n\
    \        else table[k+1][i]=table[k][table[k][i]];\n      }\n    }\n  }\n  int\
    \ lca(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n    int k=dep[v]-dep[u];\n\
    \    if(dep[v]<k)return -1;\n    for(int i=lg-1;i>=0;i--){\n      if((k>>i)&1)v=table[i][v];\n\
    \    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n      if(table[i][u]!=table[i][v]){\n\
    \        u=table[i][u];\n        v=table[i][v];\n      }\n    }\n    return table[0][u];\n\
    \  }\n  T dist(int u,int v){return sum[u]+sum[v]-2*sum[lca(u,v)];}\n  private:\n\
    \  void dfs(int idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n\
    \    for(auto &e:g[idx])if(e!=par){\n      sum[e]=sum[idx]+e.cost;\n      dfs(e,idx,d+1);\n\
    \    }\n  }\n};\n/**\n * @brief Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\
    \u901A\u7956\u5148)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/tree/doubling_lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2022-07-25 23:15:57+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_5_C_1.test.cpp
  - test/yosupo/lca1.test.cpp
documentation_of: Graph/tree/doubling_lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/Graph/tree/doubling_lowest_common_ancestor.hpp
- /library/Graph/tree/doubling_lowest_common_ancestor.hpp.html
title: "Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
