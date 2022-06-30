---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A_2.test.cpp
    title: test/aoj/GRL/GRL_2_A_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Prim(\u6700\u5C0F\u5168\u57DF\u6728)"
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
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/mst/prim.hpp\"\ntemplate<typename\
    \ T>\nstruct mst{\n  T cost;\n  Edges<T>edges;\n};\ntemplate<typename T>\nmst<T>prim(const\
    \ Graph<T>&g){\n  T sum=T();\n  vector<bool>used(g.size(),false);\n  vector<Edge<T>>dist(g.size());\n\
    \  using pi=pair<T,int>;\n  priority_queue<pi,vector<pi>,greater<>>q;\n  q.emplace(T(),0);\n\
    \  Edges<T>edges;\n  while(!q.empty()){\n    auto p=q.top();q.pop();\n    if(used[p.second])continue;\n\
    \    used[p.second]=true;\n    sum+=p.first;\n    if(dist[p.second])edges.emplace_back(dist[p.second]);\n\
    \    for(auto &e:g[p.second]){\n      if(used[e]||(dist[e]&&dist[e].cost<=e.cost))continue;\n\
    \      q.emplace(e.cost,e.to);\n    }\n  }\n  return {sum,edges};\n}\n/**\n *\
    \ @brief Prim(\u6700\u5C0F\u5168\u57DF\u6728)\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T>\nstruct mst{\n  T\
    \ cost;\n  Edges<T>edges;\n};\ntemplate<typename T>\nmst<T>prim(const Graph<T>&g){\n\
    \  T sum=T();\n  vector<bool>used(g.size(),false);\n  vector<Edge<T>>dist(g.size());\n\
    \  using pi=pair<T,int>;\n  priority_queue<pi,vector<pi>,greater<>>q;\n  q.emplace(T(),0);\n\
    \  Edges<T>edges;\n  while(!q.empty()){\n    auto p=q.top();q.pop();\n    if(used[p.second])continue;\n\
    \    used[p.second]=true;\n    sum+=p.first;\n    if(dist[p.second])edges.emplace_back(dist[p.second]);\n\
    \    for(auto &e:g[p.second]){\n      if(used[e]||(dist[e]&&dist[e].cost<=e.cost))continue;\n\
    \      q.emplace(e.cost,e.to);\n    }\n  }\n  return {sum,edges};\n}\n/**\n *\
    \ @brief Prim(\u6700\u5C0F\u5168\u57DF\u6728)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/mst/prim.hpp
  requiredBy: []
  timestamp: '2022-01-23 11:55:23+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_2_A_2.test.cpp
documentation_of: Graph/mst/prim.hpp
layout: document
redirect_from:
- /library/Graph/mst/prim.hpp
- /library/Graph/mst/prim.hpp.html
title: "Prim(\u6700\u5C0F\u5168\u57DF\u6728)"
---
