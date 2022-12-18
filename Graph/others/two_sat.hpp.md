---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/graph_template.hpp
    title: "graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  - icon: ':x:'
    path: Graph/others/scc.hpp
    title: "Strongly Connected Components(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Tow Satisfiability(2-SAT)
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
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"Graph/others/scc.hpp\"\
    \nstruct SCC:unweighted_graph{\n  public:\n  using unweighted_graph::g;\n  SCC(){}\n\
    \  SCC(int n):unweighted_graph(n){}\n  SCC(const unweighted_graph&g):unweighted_graph(g){}\n\
    \  void build(){\n    rg=unweighted_graph(g.size());\n    for(size_t i=0;i<g.size();i++){\n\
    \      for(auto&e:g[i]){\n        rg.add_edge(e.to,i,e.cost,true);\n      }\n\
    \    }\n    comp.assign(g.size(),-1);\n    used.assign(g.size(),false);\n    for(size_t\
    \ i=0;i<g.size();i++)dfs(i);\n    reverse(ord.begin(),ord.end());\n    cnt=0;\n\
    \    for(auto i:ord)if(comp[i]==-1)rdfs(i,cnt),cnt++;\n  }\n  void add(int u,int\
    \ v){unweighted_graph::add_edge(u,v,true);}\n  int operator[](int k)const{return\
    \ comp[k];}\n  vector<vector<int>>scc(){\n    if(!group.empty())return group;\n\
    \    group.resize(cnt);\n    for(size_t i=0;i<g.size();i++)group[comp[i]].emplace_back(i);\n\
    \    return group;\n  }\n  unweighted_graph DAG(){\n    if(dag.size())return dag;\n\
    \    dag=unweighted_graph(cnt);\n    for(size_t i=0;i<g.size();i++){\n      for(auto&e:g[i]){\n\
    \        if(comp[i]!=comp[e.to])dag.add_edge(comp[i],comp[e.to],true);\n     \
    \ }\n    }\n    return dag;\n  }\n  private:\n  unweighted_graph rg;\n  vector<int>comp,ord;\n\
    \  vector<bool>used;\n  int cnt;\n  vector<vector<int>>group;\n  unweighted_graph\
    \ dag;\n  void dfs(int idx){\n    if(used[idx])return;\n    used[idx]=true;\n\
    \    for(auto&to:g[idx])dfs(to);\n    ord.emplace_back(idx);\n  }\n  void rdfs(int\
    \ idx,int k){\n    if(comp[idx]!=-1)return;\n    comp[idx]=k;\n    for(auto&to:rg[idx])rdfs(to,k);\n\
    \  }\n};\n/**\n * @brief Strongly Connected Components(\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3)\n*/\n#line 3 \"Graph/others/two_sat.hpp\"\nstruct two_sat{\n\
    \  private:\n  int n;\n  SCC scc;\n  vector<bool>ans;\n  public:\n  two_sat(){}\n\
    \  two_sat(int n):n(n),scc(2*n),ans(n){}\n  void add_clause(int i,bool f,int j,bool\
    \ g){    \n    scc.add(i+(f?n:0),j+(g?0:n));\n    scc.add(j+(g?n:0),i+(f?0:n));\n\
    \  }\n  void add_equal(int i,int j){\n    add_clause(i,true,j,false);\n    add_clause(i,false,j,true);\n\
    \  }\n  void add_neq(int i,int j){\n    add_clause(i,true,j,true);\n    add_clause(i,false,j,false);\n\
    \  }\n  void add_true(int i){\n    scc.add(i+n,i);\n  }\n  void add_false(int\
    \ i){\n    scc.add(i,i+n);\n  }\n  vector<bool>calc(){\n    scc.build();\n   \
    \ for(int i=0;i<n;i++){\n      if(scc[i]==scc[i+n])return vector<bool>();\n  \
    \    ans[i]=scc[i+n]<scc[i];\n    }\n    return ans;\n  }\n};\n/**\n * @brief\
    \ Tow Satisfiability(2-SAT)\n*/\n"
  code: "#pragma once\n#include\"scc.hpp\"\nstruct two_sat{\n  private:\n  int n;\n\
    \  SCC scc;\n  vector<bool>ans;\n  public:\n  two_sat(){}\n  two_sat(int n):n(n),scc(2*n),ans(n){}\n\
    \  void add_clause(int i,bool f,int j,bool g){    \n    scc.add(i+(f?n:0),j+(g?0:n));\n\
    \    scc.add(j+(g?n:0),i+(f?0:n));\n  }\n  void add_equal(int i,int j){\n    add_clause(i,true,j,false);\n\
    \    add_clause(i,false,j,true);\n  }\n  void add_neq(int i,int j){\n    add_clause(i,true,j,true);\n\
    \    add_clause(i,false,j,false);\n  }\n  void add_true(int i){\n    scc.add(i+n,i);\n\
    \  }\n  void add_false(int i){\n    scc.add(i,i+n);\n  }\n  vector<bool>calc(){\n\
    \    scc.build();\n    for(int i=0;i<n;i++){\n      if(scc[i]==scc[i+n])return\
    \ vector<bool>();\n      ans[i]=scc[i+n]<scc[i];\n    }\n    return ans;\n  }\n\
    };\n/**\n * @brief Tow Satisfiability(2-SAT)\n*/"
  dependsOn:
  - Graph/others/scc.hpp
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/others/two_sat.hpp
  requiredBy: []
  timestamp: '2022-07-13 13:47:02+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: Graph/others/two_sat.hpp
layout: document
redirect_from:
- /library/Graph/others/two_sat.hpp
- /library/Graph/others/two_sat.hpp.html
title: Tow Satisfiability(2-SAT)
---
