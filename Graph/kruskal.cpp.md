---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Data_Structure/dsu.cpp
    title: Data_Structure/dsu.cpp
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
    \ 2 \"Graph/kruskal.cpp\"\ntemplate<typename T>\nstruct mst{\n  T cost;\n  vector<tuple<T,T,T>>edges;\n\
    };\ntemplate<typename T>\nmst<T> kruskal(vector<tuple<T,T,T>>edges,int v){\n \
    \ sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){\n\
    \    return get<2>(a)<get<2>(b);\n  });\n  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }\n"
  code: "#include\"../Data_Structure/dsu.cpp\"\ntemplate<typename T>\nstruct mst{\n\
    \  T cost;\n  vector<tuple<T,T,T>>edges;\n};\ntemplate<typename T>\nmst<T> kruskal(vector<tuple<T,T,T>>edges,int\
    \ v){\n  sort(edges.begin(),edges.end(),[](const tuple<T,T,T>&a,const tuple<T,T,T>&b){\n\
    \    return get<2>(a)<get<2>(b);\n  });\n  dsu d(v);\n  T total=0;\n  vector<tuple<T,T,T>>es;\n\
    \  for(auto &e:edges){\n    if(!d.same(get<0>(e),get<1>(e))){\n      d.merge(get<0>(e),get<1>(e));\n\
    \      es.emplace_back(e);\n      total+=get<2>(e);\n    }\n  }\n  return {total,es};\n\
    }"
  dependsOn:
  - Data_Structure/dsu.cpp
  isVerificationFile: false
  path: Graph/kruskal.cpp
  requiredBy: []
  timestamp: '2021-11-17 21:04:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/kruskal.cpp
layout: document
redirect_from:
- /library/Graph/kruskal.cpp
- /library/Graph/kruskal.cpp.html
title: Graph/kruskal.cpp
---
