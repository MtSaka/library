---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/dsu.hpp
    title: Disjoint Set Union(Union Find)
  - icon: ':heavy_check_mark:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A.test.cpp
    title: test/aoj/GRL/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
    links: []
  bundledCode: "#line 1 \"Graph/kruskal.hpp\"\n/**\n * @brief Kruskal(\u6700\u5C0F\
    \u5168\u57DF\u6728)\n*/\n#line 1 \"Data_Structure/dsu.hpp\"\n/**\n * @brief Disjoint\
    \ Set Union(Union Find)\n*/\nstruct dsu{\n  vector<int>p;\n  dsu(int n):p(n,-1){}\n\
    \  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}\n  bool same(int x,int y){return\
    \ root(x)==root(y);}\n  int size(int x){return -p[root(x)];}\n  void merge(int\
    \ x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return;\n    if(p[x]>p[y])swap(x,y);\n\
    \    p[x]+=p[y];p[y]=x;\n  }\n};\n#line 1 \"Graph/graph_template.hpp\"\n/**\n\
    \ * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    )\n*/\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n  int\
    \ idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n  bool operator<(const Edge&e)const{return\
    \ cost<e.cost;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\ntemplate<typename T=int>\nusing\
    \ Edges=vector<Edge<T>>;\n#line 6 \"Graph/kruskal.hpp\"\ntemplate<typename T>\n\
    struct mst{\n  T cost;\n  Edges<T>edges;\n};\ntemplate<typename T>\nmst<T>kruskal(Edges<T>&edges,int\
    \ v){\n  sort(edges.begin(),edges.end());\n  dsu d(v);\n  T total=0;\n  Edges<T>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(e.to,e.from)){\n      d.merge(e.to,e.from);\n\
    \      es.emplace_back(e);\n      total+=e.cost;\n    }\n  }\n  return {total,es};\n\
    }\n"
  code: "/**\n * @brief Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)\n*/\n#include\"../Data_Structure/dsu.hpp\"\
    \n#include\"graph_template.hpp\"\ntemplate<typename T>\nstruct mst{\n  T cost;\n\
    \  Edges<T>edges;\n};\ntemplate<typename T>\nmst<T>kruskal(Edges<T>&edges,int\
    \ v){\n  sort(edges.begin(),edges.end());\n  dsu d(v);\n  T total=0;\n  Edges<T>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(e.to,e.from)){\n      d.merge(e.to,e.from);\n\
    \      es.emplace_back(e);\n      total+=e.cost;\n    }\n  }\n  return {total,es};\n\
    }"
  dependsOn:
  - Data_Structure/dsu.hpp
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/kruskal.hpp
  requiredBy: []
  timestamp: '2022-01-05 17:21:33+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_2_A.test.cpp
documentation_of: Graph/kruskal.hpp
layout: document
redirect_from:
- /library/Graph/kruskal.hpp
- /library/Graph/kruskal.hpp.html
title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
---
