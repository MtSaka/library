---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/graph_template.hpp
    title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_4_A.test.cpp
    title: test/aoj/GRL/GRL_4_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Cycle Detection(\u9589\u8DEF\u691C\u51FA)"
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
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/others/detect_cycle.hpp\"\
    \ntemplate<typename T>\nbool detect_cycle(const graph<T>&g){\n  const int n=g.size();\n\
    \  vector<int>deg(n,0);\n  for(int i=0;i<n;i++)for(auto &e:g[i])deg[e]++;\n  queue<int>q;\n\
    \  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n  while(!q.empty()){\n    int\
    \ u=q.front();q.pop();\n    for(auto &e:g[u]){\n      deg[e]--;\n      if(deg[e]==0)q.push(e);\n\
    \    }\n  }\n  for(int i=0;i<n;i++)if(deg[i]!=0)return true;\n  return false;\n\
    }\n/**\n * @brief Cycle Detection(\u9589\u8DEF\u691C\u51FA)\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T>\nbool detect_cycle(const\
    \ graph<T>&g){\n  const int n=g.size();\n  vector<int>deg(n,0);\n  for(int i=0;i<n;i++)for(auto\
    \ &e:g[i])deg[e]++;\n  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n\
    \  while(!q.empty()){\n    int u=q.front();q.pop();\n    for(auto &e:g[u]){\n\
    \      deg[e]--;\n      if(deg[e]==0)q.push(e);\n    }\n  }\n  for(int i=0;i<n;i++)if(deg[i]!=0)return\
    \ true;\n  return false;\n}\n/**\n * @brief Cycle Detection(\u9589\u8DEF\u691C\
    \u51FA)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/others/detect_cycle.hpp
  requiredBy: []
  timestamp: '2022-07-12 23:30:53+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_4_A.test.cpp
documentation_of: Graph/others/detect_cycle.hpp
layout: document
redirect_from:
- /library/Graph/others/detect_cycle.hpp
- /library/Graph/others/detect_cycle.hpp.html
title: "Cycle Detection(\u9589\u8DEF\u691C\u51FA)"
---
