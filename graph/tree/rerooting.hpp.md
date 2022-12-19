---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_5_B.test.cpp
    title: test/aoj/GRL/GRL_5_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "ReRooting(\u5168\u65B9\u4F4D\u6728DP)"
    links: []
  bundledCode: "#line 1 \"graph/tree/rerooting.hpp\"\ntemplate<typename S,typename\
    \ T=S>\nstruct ReRooting{\n  struct Edge{\n    int from,to;\n    S cost;\n   \
    \ T dp,ndp;\n  };\n  using F=function<T(T,T)>;\n  using G=function<T(T,Edge)>;\n\
    \  vector<vector<Edge>>graph;\n  const F f;\n  const G g;\n  const T id;\n  vector<T>subdp,dp;\n\
    \  void add_edge(int u,int v,const S&d) {\n    graph[u].emplace_back(Edge{u,v,d,id,id});\n\
    \    graph[v].emplace_back(Edge{v,u,d,id,id});\n  }\n  void add_directed_edge(int\
    \ u,int v,const S&d) {\n    graph[u].emplace_back(Edge{u,v,d,id,id});\n  }\n \
    \ ReRooting(int n,const F&f,const G&g,const T&id=T{}):graph(n),f(f),g(g),id(id),subdp(n,id),dp(n,id){}\n\
    \  void dfs_sub(int x,int p){\n    for(auto&e:graph[x])if(e.to!=p){\n      dfs_sub(e.to,x);\n\
    \      e.dp=g(subdp[e.to],e);\n      subdp[x]=f(subdp[x],e.dp);\n    }\n  }\n\
    \  void dfs_all(int x,int p,T top) {\n    T now=id;\n    for(auto&e:graph[x]){\n\
    \      e.ndp=now;\n      if(e.to==p)e.dp=g(top,e);\n      now=f(now,e.dp);\n \
    \   }\n    dp[x]=now;\n    now=id;\n    for(int i=(int)graph[x].size()-1;i>=0;i--){\n\
    \      auto&e=graph[x][i];\n      if(e.to!=p)dfs_all(e.to,x,f(e.ndp,now));\n \
    \     now=f(e.dp,now);\n    }\n  }\n  vector<T>solve(){\n    dfs_sub(0,-1);\n\
    \    dfs_all(0,-1,id);\n    return dp;\n  }\n};\n/**\n * @brief ReRooting(\u5168\
    \u65B9\u4F4D\u6728DP)\n*/\n"
  code: "template<typename S,typename T=S>\nstruct ReRooting{\n  struct Edge{\n  \
    \  int from,to;\n    S cost;\n    T dp,ndp;\n  };\n  using F=function<T(T,T)>;\n\
    \  using G=function<T(T,Edge)>;\n  vector<vector<Edge>>graph;\n  const F f;\n\
    \  const G g;\n  const T id;\n  vector<T>subdp,dp;\n  void add_edge(int u,int\
    \ v,const S&d) {\n    graph[u].emplace_back(Edge{u,v,d,id,id});\n    graph[v].emplace_back(Edge{v,u,d,id,id});\n\
    \  }\n  void add_directed_edge(int u,int v,const S&d) {\n    graph[u].emplace_back(Edge{u,v,d,id,id});\n\
    \  }\n  ReRooting(int n,const F&f,const G&g,const T&id=T{}):graph(n),f(f),g(g),id(id),subdp(n,id),dp(n,id){}\n\
    \  void dfs_sub(int x,int p){\n    for(auto&e:graph[x])if(e.to!=p){\n      dfs_sub(e.to,x);\n\
    \      e.dp=g(subdp[e.to],e);\n      subdp[x]=f(subdp[x],e.dp);\n    }\n  }\n\
    \  void dfs_all(int x,int p,T top) {\n    T now=id;\n    for(auto&e:graph[x]){\n\
    \      e.ndp=now;\n      if(e.to==p)e.dp=g(top,e);\n      now=f(now,e.dp);\n \
    \   }\n    dp[x]=now;\n    now=id;\n    for(int i=(int)graph[x].size()-1;i>=0;i--){\n\
    \      auto&e=graph[x][i];\n      if(e.to!=p)dfs_all(e.to,x,f(e.ndp,now));\n \
    \     now=f(e.dp,now);\n    }\n  }\n  vector<T>solve(){\n    dfs_sub(0,-1);\n\
    \    dfs_all(0,-1,id);\n    return dp;\n  }\n};\n/**\n * @brief ReRooting(\u5168\
    \u65B9\u4F4D\u6728DP)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2022-12-18 21:52:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_5_B.test.cpp
documentation_of: graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/graph/tree/rerooting.hpp
- /library/graph/tree/rerooting.hpp.html
title: "ReRooting(\u5168\u65B9\u4F4D\u6728DP)"
---
