---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
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
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighted=false,bool direct=false){\n\
    \    int a,b;\n    T c=T(1);\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n  \
    \    a+=padding;\n      b+=padding;\n      if(weighted)cin>>c;\n      add_edge(a,b,c,direct);\n\
    \    }\n  }\n};\nstruct unweighted_edge{\n  template<class... Args>unweighted_edge(const\
    \ Args&...){}\n  operator int()const{return 1;}\n};\nistream &operator>>(istream&is,unweighted_edge&c){c=unweighted_edge();return\
    \ is;}\nusing unweighted_graph=graph<unweighted_edge>;\n/**\n * @brief graph Template(\u30B0\
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/mst/prim.hpp\"\
    \ntemplate<typename T>\nstruct mst{\n  T cost;\n  edges<T>es;\n};\ntemplate<typename\
    \ T>\nmst<T>prim(const graph<T>&g){\n  T sum=T();\n  vector<bool>used(g.size(),false);\n\
    \  vector<edge<T>>dist(g.size());\n  using pi=pair<T,int>;\n  priority_queue<pi,vector<pi>,greater<>>q;\n\
    \  q.emplace(T(),0);\n  edges<T>es;\n  while(!q.empty()){\n    auto p=q.top();q.pop();\n\
    \    if(used[p.second])continue;\n    used[p.second]=true;\n    sum+=p.first;\n\
    \    if(dist[p.second])es.emplace_back(dist[p.second]);\n    for(auto &e:g[p.second]){\n\
    \      if(used[e]||(dist[e]&&dist[e].cost<=e.cost))continue;\n      q.emplace(e.cost,e.to);\n\
    \    }\n  }\n  return {sum,es};\n}\n/**\n * @brief Prim(\u6700\u5C0F\u5168\u57DF\
    \u6728)\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T>\nstruct mst{\n  T\
    \ cost;\n  edges<T>es;\n};\ntemplate<typename T>\nmst<T>prim(const graph<T>&g){\n\
    \  T sum=T();\n  vector<bool>used(g.size(),false);\n  vector<edge<T>>dist(g.size());\n\
    \  using pi=pair<T,int>;\n  priority_queue<pi,vector<pi>,greater<>>q;\n  q.emplace(T(),0);\n\
    \  edges<T>es;\n  while(!q.empty()){\n    auto p=q.top();q.pop();\n    if(used[p.second])continue;\n\
    \    used[p.second]=true;\n    sum+=p.first;\n    if(dist[p.second])es.emplace_back(dist[p.second]);\n\
    \    for(auto &e:g[p.second]){\n      if(used[e]||(dist[e]&&dist[e].cost<=e.cost))continue;\n\
    \      q.emplace(e.cost,e.to);\n    }\n  }\n  return {sum,es};\n}\n/**\n * @brief\
    \ Prim(\u6700\u5C0F\u5168\u57DF\u6728)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/mst/prim.hpp
  requiredBy: []
  timestamp: '2022-07-12 23:30:53+01:00'
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
