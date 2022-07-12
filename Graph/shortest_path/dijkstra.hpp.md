---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/graph_template.hpp
    title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_1_A.test.cpp
    title: test/aoj/GRL/GRL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
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
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c=T(1);\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n  \
    \    a+=padding;\n      b+=padding;\n      if(weighed)cin>>c;\n      add_edge(a,b,c,dierct);\n\
    \    }\n  }\n};\nstruct unweighted_edge{\n  template<class... Args>unweighted_edge(const\
    \ Args&...){}\n  operator int()const{return 1;}\n};\nusing unweighted_graph=graph<unweighted_edge>;\n\
    /**\n * @brief graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\
    \u30C8)\n*/\n#line 2 \"Graph/shortest_path/dijkstra.hpp\"\ntemplate<typename T>\n\
    vector<T>dijkstra(const graph<T>&g,int s){\n  const int n=g.size();\n  const T\
    \ MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n  d[s]=0;\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        q.emplace(d[e],e);\n      }\n    }\n  }\n\
    \  return d;\n}\n/**\n * @brief Dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\
    )\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T>\nvector<T>dijkstra(const\
    \ graph<T>&g,int s){\n  const int n=g.size();\n  const T MAX=numeric_limits<T>::max()/2;\n\
    \  vector<T>d(n,MAX);\n  d[s]=0;\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        q.emplace(d[e],e);\n      }\n    }\n  }\n\
    \  return d;\n}\n/**\n * @brief Dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\
    )\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/shortest_path/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-07-12 21:46:57+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_1_A.test.cpp
documentation_of: Graph/shortest_path/dijkstra.hpp
layout: document
redirect_from:
- /library/Graph/shortest_path/dijkstra.hpp
- /library/Graph/shortest_path/dijkstra.hpp.html
title: "Dijkstra(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
---
