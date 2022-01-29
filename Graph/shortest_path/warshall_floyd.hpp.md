---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_1_C.test.cpp
    title: test/aoj/GRL/GRL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
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
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/shortest_path/warshall_floyd.hpp\"\
    \ntemplate<typename T>\nvector<vector<T>>warshall_floyd(const Graph<T>&g){\n \
    \ const int n=g.size();\n  const T MAX=numeric_limits<T>::max()/2;\n  vector<vector<T>>d(n,vector<T>(n,MAX));\n\
    \  for(int i=0;i<n;i++){\n    d[i][i]=0;\n    for(auto &e:g[i])d[i][e]=e.cost;\n\
    \  }\n  for(int k=0;k<n;k++){\n    for(int i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n\
    \        if(d[i][k]!=MAX&d[k][j]!=MAX){\n          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);\n\
    \        }\n      }\n    }\n  }\n  return d;\n}\n/**\n * @brief Warshall Floyd(\u5168\
    \u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T>\nvector<vector<T>>warshall_floyd(const\
    \ Graph<T>&g){\n  const int n=g.size();\n  const T MAX=numeric_limits<T>::max()/2;\n\
    \  vector<vector<T>>d(n,vector<T>(n,MAX));\n  for(int i=0;i<n;i++){\n    d[i][i]=0;\n\
    \    for(auto &e:g[i])d[i][e]=e.cost;\n  }\n  for(int k=0;k<n;k++){\n    for(int\
    \ i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n        if(d[i][k]!=MAX&d[k][j]!=MAX){\n\
    \          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);\n        }\n      }\n    }\n\
    \  }\n  return d;\n}\n/**\n * @brief Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\
    \u77ED\u8DEF)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/shortest_path/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2022-01-23 11:55:23+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_1_C.test.cpp
documentation_of: Graph/shortest_path/warshall_floyd.hpp
layout: document
redirect_from:
- /library/Graph/shortest_path/warshall_floyd.hpp
- /library/Graph/shortest_path/warshall_floyd.hpp.html
title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
---