---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Centroid(\u6728\u306E\u91CD\u5FC3)"
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
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 3 \"Graph/tree/centroid.hpp\"\ntemplate<typename\
    \ T>\nvector<int>centroid(const Graph<T>&g){\n  cont int n=g.size();\n  stack<pair<int,int>>s;\n\
    \  s.emplace(0,-1);\n  vector<int>sz(n),par(n);\n  while(!s.empty()){\n    auto\
    \ p=s.top();\n    if(sz[p.first]==0){\n      sz[p.first]=1;\n      for(auto &to:g[p.first])if(to!=p.second)s.emplace(to,p.first);\n\
    \    }\n    else{\n      for(auto &to:g[p.first])if(to!=p.second)sz[p.first]+=sz[to];\n\
    \      par[p.first]=p.second;\n      s.pop();\n    }\n  }\n  vector<int>res;\n\
    \  int siz=n;\n  for(int i=0;i<n;i++){\n    int val=n-sz[i];\n    for(auto &to:g[i])if(to!=par[i])val=max(val,sz[to]);\n\
    \    if(val<siz)size=val,res.clear();\n    if(val==siz)res.emplace_back(i);\n\
    \  }\n  return res;\n}\n/**\n * @brief Centroid(\u6728\u306E\u91CD\u5FC3)\n*/\n"
  code: "#pragma once\n#include\"../graph_template.hpp\"\ntemplate<typename T>\nvector<int>centroid(const\
    \ Graph<T>&g){\n  cont int n=g.size();\n  stack<pair<int,int>>s;\n  s.emplace(0,-1);\n\
    \  vector<int>sz(n),par(n);\n  while(!s.empty()){\n    auto p=s.top();\n    if(sz[p.first]==0){\n\
    \      sz[p.first]=1;\n      for(auto &to:g[p.first])if(to!=p.second)s.emplace(to,p.first);\n\
    \    }\n    else{\n      for(auto &to:g[p.first])if(to!=p.second)sz[p.first]+=sz[to];\n\
    \      par[p.first]=p.second;\n      s.pop();\n    }\n  }\n  vector<int>res;\n\
    \  int siz=n;\n  for(int i=0;i<n;i++){\n    int val=n-sz[i];\n    for(auto &to:g[i])if(to!=par[i])val=max(val,sz[to]);\n\
    \    if(val<siz)size=val,res.clear();\n    if(val==siz)res.emplace_back(i);\n\
    \  }\n  return res;\n}\n/**\n * @brief Centroid(\u6728\u306E\u91CD\u5FC3)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/tree/centroid.hpp
  requiredBy: []
  timestamp: '2022-01-27 17:25:29+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/tree/centroid.hpp
layout: document
redirect_from:
- /library/Graph/tree/centroid.hpp
- /library/Graph/tree/centroid.hpp.html
title: "Centroid(\u6728\u306E\u91CD\u5FC3)"
---
