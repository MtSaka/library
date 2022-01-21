---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/bellman_ford.hpp
    title: "Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/detect_cycle.hpp
    title: "Cycle Detection(\u9589\u8DEF\u691C\u51FA)"
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.hpp
    title: "Dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra_path.hpp
    title: "Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\u70B9\u6700\
      \u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: Graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: Graph/prim.hpp
    title: "Prim(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: Graph/topological_sort.hpp
    title: "Topological Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: Graph/warshall_floyd.hpp
    title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_1_A.test.cpp
    title: test/aoj/GRL/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_1_B.test.cpp
    title: test/aoj/GRL/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_1_C.test.cpp
    title: test/aoj/GRL/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A.test.cpp
    title: test/aoj/GRL/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A_2.test.cpp
    title: test/aoj/GRL/GRL_2_A_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_4_A.test.cpp
    title: test/aoj/GRL/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_4_B.test.cpp
    title: test/aoj/GRL/GRL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_C.test.cpp
    title: test/aoj/GRL/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8)"
    links: []
  bundledCode: "#line 1 \"Graph/graph_template.hpp\"\ntemplate<typename T=int>\nstruct\
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
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n"
  code: "template<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n  int\
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
    \ Edges=vector<Edge<T>>;\n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph_template.hpp
  requiredBy:
  - Graph/detect_cycle.hpp
  - Graph/bellman_ford.hpp
  - Graph/warshall_floyd.hpp
  - Graph/kruskal.hpp
  - Graph/dijkstra_path.hpp
  - Graph/lowest_common_ancestor.hpp
  - Graph/topological_sort.hpp
  - Graph/prim.hpp
  - Graph/dijkstra.hpp
  timestamp: '2022-01-11 21:49:44+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_4_A.test.cpp
  - test/aoj/GRL/GRL_2_A_2.test.cpp
  - test/aoj/GRL/GRL_2_A.test.cpp
  - test/aoj/GRL/GRL_1_B.test.cpp
  - test/aoj/GRL/GRL_4_B.test.cpp
  - test/aoj/GRL/GRL_5_C.test.cpp
  - test/aoj/GRL/GRL_1_A.test.cpp
  - test/aoj/GRL/GRL_1_C.test.cpp
  - test/yosupo/shortest_path.test.cpp
  - test/yosupo/lca.test.cpp
documentation_of: Graph/graph_template.hpp
layout: document
redirect_from:
- /library/Graph/graph_template.hpp
- /library/Graph/graph_template.hpp.html
title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
---
