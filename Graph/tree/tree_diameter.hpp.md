---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_A.test.cpp
    title: test/aoj/GRL/GRL_5_A.test.cpp
  - icon: ':x:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"Graph/graph_template.hpp\"\ntemplate<typename T=int>\nstruct\
    \ Edge{\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n  bool operator<(const Edge&e)const{return cost<e.cost;}\n\
    };\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n  int\
    \ es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\ntemplate<typename T=int>\nusing\
    \ Edges=vector<Edge<T>>;\n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 3 \"Graph/tree/tree_diameter.hpp\"\n\
    template<typename T=int>\nstruct TreeDiameter:Graph<T>{\n  using Graph<T>::Graph;\n\
    \  using Graph<T>::g;\n  vector<Edge<T>>path;\n  T build(){\n    to.assign(g.size(),-1);\n\
    \    auto p=dfs(0,-1);\n    auto q=dfs(p.second,-1);\n    int now=p.second;\n\
    \    while(now!=q.second){\n      for(auto &e:g[now]){\n        if(to[now]==e.to)path.emplace_back(e);\n\
    \      }\n      now=to[now];\n    }\n    return q.first;\n  }\n  TreeDiameter(const\
    \ Graph<T>&g):Graph<T>(g){}\n  private:\n  vector<int>to;\n  pair<T,int>dfs(int\
    \ idx,int par){\n    pair<T,int>res(0,idx);\n    for(auto &e:g[idx])if(e.to!=par){\n\
    \      auto cost=dfs(e.to,idx);\n      cost.first+=e.cost;\n      if(res<cost)res=cost,to[idx]=e.to;\n\
    \    }\n    return res;\n  }\n};\n/**\n * @brief Tree Diameter(\u6728\u306E\u76F4\
    \u5F84)\n*/\n"
  code: "#pragma once\n#include\"../graph_template.hpp\"\ntemplate<typename T=int>\n\
    struct TreeDiameter:Graph<T>{\n  using Graph<T>::Graph;\n  using Graph<T>::g;\n\
    \  vector<Edge<T>>path;\n  T build(){\n    to.assign(g.size(),-1);\n    auto p=dfs(0,-1);\n\
    \    auto q=dfs(p.second,-1);\n    int now=p.second;\n    while(now!=q.second){\n\
    \      for(auto &e:g[now]){\n        if(to[now]==e.to)path.emplace_back(e);\n\
    \      }\n      now=to[now];\n    }\n    return q.first;\n  }\n  TreeDiameter(const\
    \ Graph<T>&g):Graph<T>(g){}\n  private:\n  vector<int>to;\n  pair<T,int>dfs(int\
    \ idx,int par){\n    pair<T,int>res(0,idx);\n    for(auto &e:g[idx])if(e.to!=par){\n\
    \      auto cost=dfs(e.to,idx);\n      cost.first+=e.cost;\n      if(res<cost)res=cost,to[idx]=e.to;\n\
    \    }\n    return res;\n  }\n};\n/**\n * @brief Tree Diameter(\u6728\u306E\u76F4\
    \u5F84)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/tree/tree_diameter.hpp
  requiredBy: []
  timestamp: '2022-01-26 17:17:09+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/tree_diameter.test.cpp
  - test/aoj/GRL/GRL_5_A.test.cpp
documentation_of: Graph/tree/tree_diameter.hpp
layout: document
redirect_from:
- /library/Graph/tree/tree_diameter.hpp
- /library/Graph/tree/tree_diameter.hpp.html
title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
---
