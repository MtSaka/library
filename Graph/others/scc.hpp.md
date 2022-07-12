---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy:
  - icon: ':x:'
    path: Graph/others/two_sat.hpp
    title: Tow Satisfiability(2-SAT)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_3_C.test.cpp
    title: test/aoj/GRL/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: "Strongly Connected Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3)"
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
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/others/scc.hpp\"\ntemplate<typename\
    \ T=int>\nstruct SCC:Graph<T>{\n  public:\n  using Graph<T>::Graph;\n  using Graph<T>::g;\n\
    \  vector<vector<int>>group;\n  Graph<T>dag;\n  SCC(){}\n  SCC(int n):Graph<T>(n){}\n\
    \  SCC(const Graph<T>&g):Graph<T>(g){}\n  void build(){\n    rg=Graph<T>(g.size());\n\
    \    for(size_t i=0;i<g.size();i++){\n      for(auto&e:g[i]){\n        rg.add_directed_edge(e.to,i,e.cost);\n\
    \      }\n    }\n    comp.assign(g.size(),-1);\n    used.assign(g.size(),false);\n\
    \    for(size_t i=0;i<g.size();i++)dfs(i);\n    reverse(ord.begin(),ord.end());\n\
    \    int cnt=0;\n    for(auto i:ord)if(comp[i]==-1)rdfs(i,cnt),cnt++;\n    dag=Graph<T>(cnt);\n\
    \    for(size_t i=0;i<g.size();i++){\n      for(auto&e:g[i]){\n        if(comp[i]!=comp[e.to])dag.add_directed_edge(comp[i],comp[e.to],e.cost);\n\
    \      }\n    }\n    group.resize(cnt);\n    for(size_t i=0;i<g.size();i++)group[comp[i]].emplace_back(i);\n\
    \  }\n  void add(int u,int v){Graph<T>::add_directed_edge(u,v);}\n  int operator[](int\
    \ k)const{return comp[k];}\n  vector<vector<int>>scc()const{return group;}\n \
    \ Graph<T>DAG()const{return dag;}\n  private:\n  Graph<T>rg;\n  vector<int>comp,ord;\n\
    \  vector<bool>used;\n  void dfs(int idx){\n    if(used[idx])return;\n    used[idx]=true;\n\
    \    for(auto&to:g[idx])dfs(to);\n    ord.emplace_back(idx);\n  }\n  void rdfs(int\
    \ idx,int k){\n    if(comp[idx]!=-1)return;\n    comp[idx]=k;\n    for(auto&to:rg.g[idx])rdfs(to,k);\n\
    \  }\n};\n/**\n * @brief Strongly Connected Components(\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3)\n*/\n"
  code: "#include\"../graph_template.hpp\"\ntemplate<typename T=int>\nstruct SCC:Graph<T>{\n\
    \  public:\n  using Graph<T>::Graph;\n  using Graph<T>::g;\n  vector<vector<int>>group;\n\
    \  Graph<T>dag;\n  SCC(){}\n  SCC(int n):Graph<T>(n){}\n  SCC(const Graph<T>&g):Graph<T>(g){}\n\
    \  void build(){\n    rg=Graph<T>(g.size());\n    for(size_t i=0;i<g.size();i++){\n\
    \      for(auto&e:g[i]){\n        rg.add_directed_edge(e.to,i,e.cost);\n     \
    \ }\n    }\n    comp.assign(g.size(),-1);\n    used.assign(g.size(),false);\n\
    \    for(size_t i=0;i<g.size();i++)dfs(i);\n    reverse(ord.begin(),ord.end());\n\
    \    int cnt=0;\n    for(auto i:ord)if(comp[i]==-1)rdfs(i,cnt),cnt++;\n    dag=Graph<T>(cnt);\n\
    \    for(size_t i=0;i<g.size();i++){\n      for(auto&e:g[i]){\n        if(comp[i]!=comp[e.to])dag.add_directed_edge(comp[i],comp[e.to],e.cost);\n\
    \      }\n    }\n    group.resize(cnt);\n    for(size_t i=0;i<g.size();i++)group[comp[i]].emplace_back(i);\n\
    \  }\n  void add(int u,int v){Graph<T>::add_directed_edge(u,v);}\n  int operator[](int\
    \ k)const{return comp[k];}\n  vector<vector<int>>scc()const{return group;}\n \
    \ Graph<T>DAG()const{return dag;}\n  private:\n  Graph<T>rg;\n  vector<int>comp,ord;\n\
    \  vector<bool>used;\n  void dfs(int idx){\n    if(used[idx])return;\n    used[idx]=true;\n\
    \    for(auto&to:g[idx])dfs(to);\n    ord.emplace_back(idx);\n  }\n  void rdfs(int\
    \ idx,int k){\n    if(comp[idx]!=-1)return;\n    comp[idx]=k;\n    for(auto&to:rg.g[idx])rdfs(to,k);\n\
    \  }\n};\n/**\n * @brief Strongly Connected Components(\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/others/scc.hpp
  requiredBy:
  - Graph/others/two_sat.hpp
  timestamp: '2022-07-12 18:04:30+01:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL/GRL_3_C.test.cpp
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: Graph/others/scc.hpp
layout: document
redirect_from:
- /library/Graph/others/scc.hpp
- /library/Graph/others/scc.hpp.html
title: "Strongly Connected Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3)"
---
