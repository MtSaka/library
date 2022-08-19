---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/mst/kruskal.hpp
    title: "Kruskal(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: Graph/mst/prim.hpp
    title: "Prim(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: Graph/others/detect_cycle.hpp
    title: "Cycle Detection(\u9589\u8DEF\u691C\u51FA)"
  - icon: ':heavy_check_mark:'
    path: Graph/others/scc.hpp
    title: "Strongly Connected Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  - icon: ':heavy_check_mark:'
    path: Graph/others/topological_sort.hpp
    title: "Topological Sort(\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  - icon: ':heavy_check_mark:'
    path: Graph/others/two_sat.hpp
    title: Tow Satisfiability(2-SAT)
  - icon: ':heavy_check_mark:'
    path: Graph/shortest_path/bellman_ford.hpp
    title: "Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/shortest_path/dijkstra.hpp
    title: "Dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/shortest_path/dijkstra_path.hpp
    title: "Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\u70B9\u6700\
      \u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/shortest_path/warshall_floyd.hpp
    title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: Graph/tree/RMQ_lowest_common_ancestor.hpp
    title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':warning:'
    path: Graph/tree/centroid.hpp
    title: "Centroid(\u6728\u306E\u91CD\u5FC3)"
  - icon: ':heavy_check_mark:'
    path: Graph/tree/doubling_lowest_common_ancestor.hpp
    title: "Doubling Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: Graph/tree/tree_diameter.hpp
    title: "Tree Diameter(\u6728\u306E\u76F4\u5F84)"
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
    path: test/aoj/GRL/GRL_3_C.test.cpp
    title: test/aoj/GRL/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_4_A.test.cpp
    title: test/aoj/GRL/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_4_B.test.cpp
    title: test/aoj/GRL/GRL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_A.test.cpp
    title: test/aoj/GRL/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_C_1.test.cpp
    title: test/aoj/GRL/GRL_5_C_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_C_2.test.cpp
    title: test/aoj/GRL/GRL_5_C_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca1.test.cpp
    title: test/yosupo/lca1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca2.test.cpp
    title: test/yosupo/lca2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8)"
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
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n"
  code: "#pragma once\ntemplate<typename T=int>\nstruct edge{\n  int from,to;\n  T\
    \ cost;\n  int idx;\n  edge(){}\n  edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n  bool operator<(const edge&e)const{return\
    \ cost<e.cost;}\n};\ntemplate<typename T=int>\nusing edges=vector<edge<T>>;\n\
    template<typename T=int>\nstruct graph{\n  vector<vector<edge<T>>>g;\n  int es;\n\
    \  graph(){}\n  explicit graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_edge(int from,int\
    \ to,T cost=1,bool direct=false){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    if(!direct)g[to].emplace_back(to,from,cost,es);\n    es++;\n  }\n  void add_edge(int\
    \ from,int to,bool direct=false){\n    g[from].emplace_back(from,to,1,es);\n \
    \   if(!direct)g[to].emplace_back(to,from,1,es);\n  }\n  inline vector<edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighted=false,bool direct=false){\n\
    \    int a,b;\n    T c=T(1);\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n  \
    \    a+=padding;\n      b+=padding;\n      if(weighted)cin>>c;\n      add_edge(a,b,c,direct);\n\
    \    }\n  }\n};\nstruct unweighted_edge{\n  template<class... Args>unweighted_edge(const\
    \ Args&...){}\n  operator int()const{return 1;}\n};\nistream &operator>>(istream&is,unweighted_edge&c){c=unweighted_edge();return\
    \ is;}\nusing unweighted_graph=graph<unweighted_edge>;\n/**\n * @brief graph Template(\u30B0\
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph_template.hpp
  requiredBy:
  - Graph/tree/tree_diameter.hpp
  - Graph/tree/doubling_lowest_common_ancestor.hpp
  - Graph/tree/RMQ_lowest_common_ancestor.hpp
  - Graph/tree/centroid.hpp
  - Graph/shortest_path/dijkstra.hpp
  - Graph/shortest_path/bellman_ford.hpp
  - Graph/shortest_path/warshall_floyd.hpp
  - Graph/shortest_path/dijkstra_path.hpp
  - Graph/others/scc.hpp
  - Graph/others/two_sat.hpp
  - Graph/others/detect_cycle.hpp
  - Graph/others/topological_sort.hpp
  - Graph/mst/kruskal.hpp
  - Graph/mst/prim.hpp
  timestamp: '2022-07-12 23:30:53+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca1.test.cpp
  - test/yosupo/lca2.test.cpp
  - test/yosupo/tree_diameter.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/shortest_path.test.cpp
  - test/yosupo/scc.test.cpp
  - test/aoj/GRL/GRL_1_B.test.cpp
  - test/aoj/GRL/GRL_1_C.test.cpp
  - test/aoj/GRL/GRL_2_A.test.cpp
  - test/aoj/GRL/GRL_4_A.test.cpp
  - test/aoj/GRL/GRL_5_C_1.test.cpp
  - test/aoj/GRL/GRL_4_B.test.cpp
  - test/aoj/GRL/GRL_1_A.test.cpp
  - test/aoj/GRL/GRL_3_C.test.cpp
  - test/aoj/GRL/GRL_5_A.test.cpp
  - test/aoj/GRL/GRL_5_C_2.test.cpp
  - test/aoj/GRL/GRL_2_A_2.test.cpp
documentation_of: Graph/graph_template.hpp
layout: document
redirect_from:
- /library/Graph/graph_template.hpp
- /library/Graph/graph_template.hpp.html
title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
---
