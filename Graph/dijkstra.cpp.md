---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"Graph/graph_template.cpp\"\ntemplate<typename T=int>\nstruct\
    \ Edge{\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 2 \"Graph/dijkstra.cpp\"\n\
    template<typename T>\nvector<T>dijkstra(const Graph<T>&g,int s){\n  int n=g.size();\n\
    \  T MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n  d[s]=0;\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        q.emplace(d[e],e);\n      }\n    }\n  }\n\
    \  return d;\n}\ntemplate<typename T>\npair<T,vector<int>>dijkstra_path(const\
    \ Graph<T>&g,int s,int t){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n\
    \  vector<T>d(n,MAX);\n  d[s]=0;\n  vector<int>prev(n);\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        prev[e]=u;\n        q.emplace(d[e],e);\n \
    \     }\n    }\n  }\n  if(d[t]==MAX)return {-1,{}};\n  vector<int>path;\n  path.emplace_back(t);\n\
    \  while(path.back()!=s){\n    path.emplace_back(prev[path.back()]);\n  }\n  reverse(path.begin(),path.end());\n\
    \  return {d[t],path};\n}\n"
  code: "#include\"graph_template.cpp\"\ntemplate<typename T>\nvector<T>dijkstra(const\
    \ Graph<T>&g,int s){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n\
    \  vector<T>d(n,MAX);\n  d[s]=0;\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        q.emplace(d[e],e);\n      }\n    }\n  }\n\
    \  return d;\n}\ntemplate<typename T>\npair<T,vector<int>>dijkstra_path(const\
    \ Graph<T>&g,int s,int t){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n\
    \  vector<T>d(n,MAX);\n  d[s]=0;\n  vector<int>prev(n);\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        prev[e]=u;\n        q.emplace(d[e],e);\n \
    \     }\n    }\n  }\n  if(d[t]==MAX)return {-1,{}};\n  vector<int>path;\n  path.emplace_back(t);\n\
    \  while(path.back()!=s){\n    path.emplace_back(prev[path.back()]);\n  }\n  reverse(path.begin(),path.end());\n\
    \  return {d[t],path};\n}"
  dependsOn:
  - Graph/graph_template.cpp
  isVerificationFile: false
  path: Graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2021-12-23 00:09:23+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/dijkstra.cpp
- /library/Graph/dijkstra.cpp.html
title: Graph/dijkstra.cpp
---
