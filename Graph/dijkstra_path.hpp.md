---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\
      \u70B9\u6700\u77ED\u8DEF)"
    links: []
  bundledCode: "#line 1 \"Graph/dijkstra_path.hpp\"\n/**\n * @brief Dijkstra With\
    \ Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)\n*/\n\
    #line 1 \"Graph/graph_template.hpp\"\n/**\n * @brief Graph Template(\u30B0\u30E9\
    \u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\ntemplate<typename T=int>\nstruct\
    \ Edge{\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/dijkstra_path.hpp\"\
    \ntemplate<typename T=int>\npair<T,vector<int>>dijkstra_path(const Graph<T>&g,int\
    \ s,int t){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n\
    \  d[s]=0;\n  vector<int>prev(n);\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        prev[e]=u;\n        q.emplace(d[e],e);\n \
    \     }\n    }\n  }\n  if(d[t]==MAX)return {-1,{}};\n  vector<int>path;\n  path.emplace_back(t);\n\
    \  while(path.back()!=s){\n    path.emplace_back(prev[path.back()]);\n  }\n  reverse(path.begin(),path.end());\n\
    \  return {d[t],path};\n}\n"
  code: "/**\n * @brief Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\
    \u70B9\u6700\u77ED\u8DEF)\n*/\n#include\"graph_template.hpp\"\ntemplate<typename\
    \ T=int>\npair<T,vector<int>>dijkstra_path(const Graph<T>&g,int s,int t){\n  int\
    \ n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n  d[s]=0;\n\
    \  vector<int>prev(n);\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        prev[e]=u;\n        q.emplace(d[e],e);\n \
    \     }\n    }\n  }\n  if(d[t]==MAX)return {-1,{}};\n  vector<int>path;\n  path.emplace_back(t);\n\
    \  while(path.back()!=s){\n    path.emplace_back(prev[path.back()]);\n  }\n  reverse(path.begin(),path.end());\n\
    \  return {d[t],path};\n}"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/dijkstra_path.hpp
  requiredBy: []
  timestamp: '2021-12-27 22:50:22+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortest_path.test.cpp
documentation_of: Graph/dijkstra_path.hpp
layout: document
redirect_from:
- /library/Graph/dijkstra_path.hpp
- /library/Graph/dijkstra_path.hpp.html
title: "Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\u70B9\u6700\u77ED\
  \u8DEF)"
---