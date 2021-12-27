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
    document_title: "Cycle Detection(\u9589\u8DEF\u691C\u51FA)"
    links: []
  bundledCode: "#line 1 \"Graph/detect_cycle.hpp\"\n/**\n * @brief Cycle Detection(\u9589\
    \u8DEF\u691C\u51FA)\n*/\n#line 1 \"Graph/graph_template.hpp\"\n/**\n * @brief\
    \ Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n\
    template<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n  int idx;\n\
    \  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
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
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/detect_cycle.hpp\"\
    \ntemplate<typename T>\nbool detect_cycle(const Graph<T>&g){\n  int n=g.size();\n\
    \  vector<int>deg(n,0);\n  for(int i=0;i<n;i++)for(auto &e:g[i])deg[e]++;\n  queue<int>q;\n\
    \  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n  while(!q.empty()){\n    int\
    \ u=q.front();q.pop();\n    for(auto &e:g[u]){\n      deg[e]--;\n      if(deg[e]==0)q.push(e);\n\
    \    }\n  }\n  for(int i=0;i<n;i++)if(deg[i]!=0)return true;\n}\n"
  code: "/**\n * @brief Cycle Detection(\u9589\u8DEF\u691C\u51FA)\n*/\n#include\"\
    graph_template.hpp\"\ntemplate<typename T>\nbool detect_cycle(const Graph<T>&g){\n\
    \  int n=g.size();\n  vector<int>deg(n,0);\n  for(int i=0;i<n;i++)for(auto &e:g[i])deg[e]++;\n\
    \  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n  while(!q.empty()){\n\
    \    int u=q.front();q.pop();\n    for(auto &e:g[u]){\n      deg[e]--;\n     \
    \ if(deg[e]==0)q.push(e);\n    }\n  }\n  for(int i=0;i<n;i++)if(deg[i]!=0)return\
    \ true;\n}"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/detect_cycle.hpp
  requiredBy: []
  timestamp: '2021-12-27 15:21:37+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/detect_cycle.hpp
layout: document
redirect_from:
- /library/Graph/detect_cycle.hpp
- /library/Graph/detect_cycle.hpp.html
title: "Cycle Detection(\u9589\u8DEF\u691C\u51FA)"
---
