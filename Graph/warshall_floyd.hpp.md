---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
    links: []
  bundledCode: "#line 1 \"Graph/warshall_floyd.hpp\"\n/**\n * @brief Warshall Floyd(\u5168\
    \u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)\n*/\n#line 1 \"Graph/graph_template.hpp\"\
    \n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n*/\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n\
    \  int idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n\
    \  vector<vector<Edge>>g;\n  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n\
    \  size_t size()const{return g.size();}\n  size_t edge_size()const{return es;}\n\
    \  void add_directed_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n\
    \  }\n  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/warshall_floyd.hpp\"\
    \ntemplate<typename T>\nvector<vector<T>>warshall_floyd(const Graph<T>&g){\n \
    \ int n=g.size();\n  T MAX=numerical_limits<T>::max()/2;\n  vector<vector<T>>d(n,vector<T>(n,MAX));\n\
    \  for(int i=0;i<n;i++)for(auto &e:g[i])d[i][e]=e.cost;\n  for(int k=0;k<n;k++){\n\
    \    for(int i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n        if(d[i][k]!=MAX&d[k][j]!=MAX){\n\
    \          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);\n        }\n      }\n    }\n\
    \  }\n  return d;\n}\n"
  code: "/**\n * @brief Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF\
    )\n*/\n#include\"graph_template.hpp\"\ntemplate<typename T>\nvector<vector<T>>warshall_floyd(const\
    \ Graph<T>&g){\n  int n=g.size();\n  T MAX=numerical_limits<T>::max()/2;\n  vector<vector<T>>d(n,vector<T>(n,MAX));\n\
    \  for(int i=0;i<n;i++)for(auto &e:g[i])d[i][e]=e.cost;\n  for(int k=0;k<n;k++){\n\
    \    for(int i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n        if(d[i][k]!=MAX&d[k][j]!=MAX){\n\
    \          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);\n        }\n      }\n    }\n\
    \  }\n  return d;\n}"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/Graph/warshall_floyd.hpp
- /library/Graph/warshall_floyd.hpp.html
title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
---
