---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_B.test.cpp
    title: test/aoj/GRL/GRL_5_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "ReRooting(\u5168\u65B9\u4F4D\u6728DP)"
    links: []
  bundledCode: "#line 1 \"Graph/rerooting.hpp\"\n/**\n * @brief ReRooting(\u5168\u65B9\
    \u4F4D\u6728DP)\n*/\ntemplate<typename S,typename T=S>\nstruct ReRooting{\n  struct\
    \ Edge{\n    int from,to;\n    S cost;\n    T dp,ndp;\n  };\n  using F=function<T(T,T)>;\n\
    \  using G=function<T(T,Edge)>;\n  vector<vector<Edge>> g;\n  const F f;\n  const\
    \ G gg;\n  const T id;\n  vector<T> subdp,dp;\n  void add_edge(int u,int v,const\
    \ S &d) {\n    g[u].emplace_back(Edge{u,v,d,id,id});\n    g[v].emplace_back(Edge{v,u,d,id,id});\n\
    \  }\n  ReRooting(int n,const F &f,const G &g,const T &id=T{}):g(n),f(f),gg(g),id(id),subdp(n,id),dp(n,id)\
    \ {}\n  void dfs_sub(int x,int p) {\n    for(auto &e:g[x])if(e.to!=p){\n     \
    \ dfs_sub(e.to,x);\n      e.dp=gg(subdp[e.to], e);\n      subdp[x]=f(subdp[x],\
    \ e.dp);\n    }\n  }\n  void dfs_all(int x,int p,T top) {\n    T now = id;\n \
    \   for(auto &e:g[x]){\n      e.ndp=now;\n      if(e.to==p)e.dp=gg(top, e);\n\
    \      now=f(now,e.dp);\n    }\n    dp[x]=now;\n    now=id;\n    for(int i=(int)g[x].size()-1;i>=0;i--){\n\
    \      auto &e=g[x][i];\n      if(e.to!= p)dfs_all(e.to,x,f(e.ndp,now));\n   \
    \   now=f(now,e.dp);\n    }\n  }\n  vector<T>solve(){\n    dfs_sub(0,-1);\n  \
    \  dfs_all(0,-1,id);\n    return dp;\n  }\n};\n"
  code: "/**\n * @brief ReRooting(\u5168\u65B9\u4F4D\u6728DP)\n*/\ntemplate<typename\
    \ S,typename T=S>\nstruct ReRooting{\n  struct Edge{\n    int from,to;\n    S\
    \ cost;\n    T dp,ndp;\n  };\n  using F=function<T(T,T)>;\n  using G=function<T(T,Edge)>;\n\
    \  vector<vector<Edge>> g;\n  const F f;\n  const G gg;\n  const T id;\n  vector<T>\
    \ subdp,dp;\n  void add_edge(int u,int v,const S &d) {\n    g[u].emplace_back(Edge{u,v,d,id,id});\n\
    \    g[v].emplace_back(Edge{v,u,d,id,id});\n  }\n  ReRooting(int n,const F &f,const\
    \ G &g,const T &id=T{}):g(n),f(f),gg(g),id(id),subdp(n,id),dp(n,id) {}\n  void\
    \ dfs_sub(int x,int p) {\n    for(auto &e:g[x])if(e.to!=p){\n      dfs_sub(e.to,x);\n\
    \      e.dp=gg(subdp[e.to], e);\n      subdp[x]=f(subdp[x], e.dp);\n    }\n  }\n\
    \  void dfs_all(int x,int p,T top) {\n    T now = id;\n    for(auto &e:g[x]){\n\
    \      e.ndp=now;\n      if(e.to==p)e.dp=gg(top, e);\n      now=f(now,e.dp);\n\
    \    }\n    dp[x]=now;\n    now=id;\n    for(int i=(int)g[x].size()-1;i>=0;i--){\n\
    \      auto &e=g[x][i];\n      if(e.to!= p)dfs_all(e.to,x,f(e.ndp,now));\n   \
    \   now=f(now,e.dp);\n    }\n  }\n  vector<T>solve(){\n    dfs_sub(0,-1);\n  \
    \  dfs_all(0,-1,id);\n    return dp;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/rerooting.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_5_B.test.cpp
documentation_of: Graph/rerooting.hpp
layout: document
redirect_from:
- /library/Graph/rerooting.hpp
- /library/Graph/rerooting.hpp.html
title: "ReRooting(\u5168\u65B9\u4F4D\u6728DP)"
---
