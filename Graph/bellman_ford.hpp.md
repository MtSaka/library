---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_1_B.test.cpp
    title: test/aoj/GRL/GRL_1_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
    links: []
  bundledCode: "#line 1 \"Graph/bellman_ford.hpp\"\n/**\n * @brief Bellman-Ford(\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)\n*/\n#line 1 \"Graph/graph_template.hpp\"\
    \n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n*/\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n\
    \  int idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n\
    \  vector<vector<Edge<T>>>g;\n  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n\
    \  size_t size()const{return g.size();}\n  size_t edge_size()const{return es;}\n\
    \  void add_directed_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n\
    \  }\n  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/bellman_ford.hpp\"\
    \ntemplate<typename T>\nvector<T>bellman_ford(const Graph<T>&g,int s){\n  int\
    \ n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n  d[s]=0;\n\
    \  for(int i=0;i<n;i++){\n    bool changed=false;\n    for(int j=0;j<n;j++){\n\
    \      for(auto &e:g[j]){\n        if(d[j]!=MAX&&d[e]>d[j]+e.cost){\n        \
    \  d[e]=d[j]+e.cost;\n          changed=true;\n        }\n      }\n    }\n   \
    \ if(!changed)return d;\n  }\n  for(int i=0;i<n;i++)for(auto &e:g[i])if(d[i]!=MAX&&d[e]>d[i]+e.cost)return\
    \ d[e]=-MAX;\n  for(int i=0;i<n-1;i++){\n    bool changed=false;\n    for(int\
    \ j=0;j<n;j++){\n      if(d[j]!=-MAX)continue;\n      for(auto &e:g[j]){\n   \
    \     if(d[e]!=-MAX){\n          d[e]=d[j]\n          changed=true;\n        }\n\
    \      }\n    }\n    if(!changed)break;\n  }\n  return d;\n}\n"
  code: "/**\n * @brief Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)\n\
    */\n#include\"graph_template.hpp\"\ntemplate<typename T>\nvector<T>bellman_ford(const\
    \ Graph<T>&g,int s){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n\
    \  vector<T>d(n,MAX);\n  d[s]=0;\n  for(int i=0;i<n;i++){\n    bool changed=false;\n\
    \    for(int j=0;j<n;j++){\n      for(auto &e:g[j]){\n        if(d[j]!=MAX&&d[e]>d[j]+e.cost){\n\
    \          d[e]=d[j]+e.cost;\n          changed=true;\n        }\n      }\n  \
    \  }\n    if(!changed)return d;\n  }\n  for(int i=0;i<n;i++)for(auto &e:g[i])if(d[i]!=MAX&&d[e]>d[i]+e.cost)return\
    \ d[e]=-MAX;\n  for(int i=0;i<n-1;i++){\n    bool changed=false;\n    for(int\
    \ j=0;j<n;j++){\n      if(d[j]!=-MAX)continue;\n      for(auto &e:g[j]){\n   \
    \     if(d[e]!=-MAX){\n          d[e]=d[j]\n          changed=true;\n        }\n\
    \      }\n    }\n    if(!changed)break;\n  }\n  return d;\n}"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-12-29 21:36:42+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_1_B.test.cpp
documentation_of: Graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/Graph/bellman_ford.hpp
- /library/Graph/bellman_ford.hpp.html
title: "Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
---
