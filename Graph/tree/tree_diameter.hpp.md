---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/graph_template.hpp
    title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
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
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c=T(1);\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n  \
    \    a+=padding;\n      b+=padding;\n      if(weighed)cin>>c;\n      add_edge(a,b,c,dierct);\n\
    \    }\n  }\n};\nstruct unweighted_edge{\n  template<class... Args>unweighted_edge(const\
    \ Args&...){}\n  operator int()const{return 1;}\n};\nusing unweighted_graph=graph<unweighted_edge>;\n\
    /**\n * @brief graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n*/\n#line 3 \"Graph/tree/tree_diameter.hpp\"\ntemplate<typename T=int>\n\
    struct TreeDiameter:graph<T>{\n  using graph<T>::graph;\n  using graph<T>::g;\n\
    \  vector<Edge<T>>path;\n  T build(){\n    to.assign(g.size(),-1);\n    auto p=dfs(0,-1);\n\
    \    auto q=dfs(p.second,-1);\n    int now=p.second;\n    while(now!=q.second){\n\
    \      for(auto &e:g[now]){\n        if(to[now]==e.to)path.emplace_back(e);\n\
    \      }\n      now=to[now];\n    }\n    return q.first;\n  }\n  TreeDiameter(const\
    \ graph<T>&g):graph<T>(g){}\n  private:\n  vector<int>to;\n  pair<T,int>dfs(int\
    \ idx,int par){\n    pair<T,int>res(0,idx);\n    for(auto &e:g[idx])if(e.to!=par){\n\
    \      auto cost=dfs(e.to,idx);\n      cost.first+=e.cost;\n      if(res<cost)res=cost,to[idx]=e.to;\n\
    \    }\n    return res;\n  }\n};\n/**\n * @brief Tree Diameter(\u6728\u306E\u76F4\
    \u5F84)\n*/\n"
  code: "#pragma once\n#include\"../graph_template.hpp\"\ntemplate<typename T=int>\n\
    struct TreeDiameter:graph<T>{\n  using graph<T>::graph;\n  using graph<T>::g;\n\
    \  vector<Edge<T>>path;\n  T build(){\n    to.assign(g.size(),-1);\n    auto p=dfs(0,-1);\n\
    \    auto q=dfs(p.second,-1);\n    int now=p.second;\n    while(now!=q.second){\n\
    \      for(auto &e:g[now]){\n        if(to[now]==e.to)path.emplace_back(e);\n\
    \      }\n      now=to[now];\n    }\n    return q.first;\n  }\n  TreeDiameter(const\
    \ graph<T>&g):graph<T>(g){}\n  private:\n  vector<int>to;\n  pair<T,int>dfs(int\
    \ idx,int par){\n    pair<T,int>res(0,idx);\n    for(auto &e:g[idx])if(e.to!=par){\n\
    \      auto cost=dfs(e.to,idx);\n      cost.first+=e.cost;\n      if(res<cost)res=cost,to[idx]=e.to;\n\
    \    }\n    return res;\n  }\n};\n/**\n * @brief Tree Diameter(\u6728\u306E\u76F4\
    \u5F84)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/tree/tree_diameter.hpp
  requiredBy: []
  timestamp: '2022-07-12 21:46:57+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/tree/tree_diameter.hpp
layout: document
redirect_from:
- /library/Graph/tree/tree_diameter.hpp
- /library/Graph/tree/tree_diameter.hpp.html
title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
---
