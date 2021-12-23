---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Data_Structure/dsu.cpp
    title: Data_Structure/dsu.cpp
  - icon: ':warning:'
    path: Graph/graph_template.cpp
    title: Graph/graph_template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structure/dsu.cpp\"\nstruct dsu{\n  vector<int>sz,par;\n\
    \  dsu(){}\n  dsu(int n){\n    sz.resize(n,1);\n    par.resize(n,0);\n    for(int\
    \ i=0;i<n;i++)par[i]=i;\n  }\n  int root(int x){\n    if(x==par[x])return x;\n\
    \    return par[x]=root(par[x]);\n  }\n  bool same(int x,int y){return root(x)==root(y);}\n\
    \  int size(int x){return sz[root(x)];}\n  void merge(int x,int y){\n    x=root(x),y=root(y);\n\
    \    if(x==y)return ;\n    if(sz[x]>sz[y]){\n      par[y]=x;\n      sz[x]+=sz[y];\n\
    \    }\n    else{\n      par[x]=y;\n      sz[y]+=sz[x];\n    }\n  }\n};\n#line\
    \ 1 \"Graph/graph_template.cpp\"\ntemplate<typename T=int>\nstruct Edge{\n  int\
    \ from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int\
    \ idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator int()const{return\
    \ to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 3 \"Graph/kruskal.cpp\"\n\
    template<typename T>\nstruct mst{\n  T cost;\n  vector<tuple<T,T,T>>edges;\n};\n\
    template<typename T>\nmst<T>kruskal(const Graph<T>&g,int v){\n  vector<tuple<T,T,T>>edges;\n\
    \  for(int i=0;i<g.size();i++){\n    for(auto &e:g[i])if(e<i)edges.emplace_back(e,i,e.cost);\n\
    \  }\n  sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){\n\
    \    return get<2>(a)<get<2>(b);\n  });\n  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }\n"
  code: "#include\"../Data_Structure/dsu.cpp\"\n#include\"graph_template.cpp\"\ntemplate<typename\
    \ T>\nstruct mst{\n  T cost;\n  vector<tuple<T,T,T>>edges;\n};\ntemplate<typename\
    \ T>\nmst<T>kruskal(const Graph<T>&g,int v){\n  vector<tuple<T,T,T>>edges;\n \
    \ for(int i=0;i<g.size();i++){\n    for(auto &e:g[i])if(e<i)edges.emplace_back(e,i,e.cost);\n\
    \  }\n  sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){\n\
    \    return get<2>(a)<get<2>(b);\n  });\n  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }"
  dependsOn:
  - Data_Structure/dsu.cpp
  - Graph/graph_template.cpp
  isVerificationFile: false
  path: Graph/kruskal.cpp
  requiredBy: []
  timestamp: '2021-12-23 00:09:23+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/kruskal.cpp
layout: document
redirect_from:
- /library/Graph/kruskal.cpp
- /library/Graph/kruskal.cpp.html
title: Graph/kruskal.cpp
---
