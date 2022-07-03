---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_4_B.test.cpp
    title: test/aoj/GRL/GRL_4_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Topological Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8)"
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
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/others/topological_sort.hpp\"\
    \ntemplate<typename T>\nstruct topological_sort{\n  int n;\n  const Graph<T>&g;\n\
    \  vector<int>order;\n  vector<bool>seen;\n  void dfs(int v){\n    seen[v]=true;\n\
    \    for(auto &e:g[v])if(!seen[e])dfs(e);\n    order.push_back(v);\n  }\n  void\
    \ init(){\n    n=g.size();\n    seen.assign(n,false);\n    order.reserve(n);\n\
    \    for(int i=0;i<n;i++)if(!seen[i])dfs(i);\n    reverse(order.begin(),order.end());\n\
    \  }\n  topological_sort(const Graph<T>&g):g(g){init();}\n  const vector<int>&get()const&{return\
    \ order;}\n  vector<int>get()&&{return move(order);}\n};\n/**\n * @brief Topological\
    \ Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T>\nstruct topological_sort{\n\
    \  int n;\n  const Graph<T>&g;\n  vector<int>order;\n  vector<bool>seen;\n  void\
    \ dfs(int v){\n    seen[v]=true;\n    for(auto &e:g[v])if(!seen[e])dfs(e);\n \
    \   order.push_back(v);\n  }\n  void init(){\n    n=g.size();\n    seen.assign(n,false);\n\
    \    order.reserve(n);\n    for(int i=0;i<n;i++)if(!seen[i])dfs(i);\n    reverse(order.begin(),order.end());\n\
    \  }\n  topological_sort(const Graph<T>&g):g(g){init();}\n  const vector<int>&get()const&{return\
    \ order;}\n  vector<int>get()&&{return move(order);}\n};\n/**\n * @brief Topological\
    \ Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/others/topological_sort.hpp
  requiredBy: []
  timestamp: '2022-01-23 11:55:23+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_4_B.test.cpp
documentation_of: Graph/others/topological_sort.hpp
layout: document
redirect_from:
- /library/Graph/others/topological_sort.hpp
- /library/Graph/others/topological_sort.hpp.html
title: "Topological Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---
