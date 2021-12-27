---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)"
    links: []
  bundledCode: "#line 1 \"Graph/negative_cycle.hpp\"\n/**\n * @brief Negative Cycle\
    \ Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)\n*/\n#line 1 \"Graph/graph_template.hpp\"\
    \n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n*/\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n\
    \  int idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
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
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/negative_cycle.hpp\"\
    \ntemplate<typename T>\nbool negative_cycle(const Graph<T>&g){\n  int n=g.size();\n\
    \  T MAX=numerical_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n  for(int i=0;i<n;i++){\n\
    \    bool update=false;\n    for(int j=0;j<n;j++){\n      for(auto &e:g[j])if(d[e]>d[j]+e.cost&&d[j]!=MAX){\n\
    \        d[e]=d[j]+e.cost;\n        update=true;\n        if(i==n-1)return true;\n\
    \      }\n    }\n    if(!update)break;\n  }\n  return false;\n}\n"
  code: "/**\n * @brief Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)\n\
    */\n#include\"graph_template.hpp\"\ntemplate<typename T>\nbool negative_cycle(const\
    \ Graph<T>&g){\n  int n=g.size();\n  T MAX=numerical_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n\
    \  for(int i=0;i<n;i++){\n    bool update=false;\n    for(int j=0;j<n;j++){\n\
    \      for(auto &e:g[j])if(d[e]>d[j]+e.cost&&d[j]!=MAX){\n        d[e]=d[j]+e.cost;\n\
    \        update=true;\n        if(i==n-1)return true;\n      }\n    }\n    if(!update)break;\n\
    \  }\n  return false;\n}"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/negative_cycle.hpp
  requiredBy: []
  timestamp: '2021-12-27 15:21:37+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/negative_cycle.hpp
layout: document
redirect_from:
- /library/Graph/negative_cycle.hpp
- /library/Graph/negative_cycle.hpp.html
title: "Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)"
---
