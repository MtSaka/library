---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_6_A.test.cpp
    title: test/aoj/GRL/GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dinic(\u6700\u5927\u6D41)"
    links: []
  bundledCode: "#line 2 \"Graph/flow/dinic.hpp\"\ntemplate<typename T>\nstruct Dinic{\n\
    \  struct edge{\n    int to;\n    T cap;\n    int rev;\n    bool isrev;\n    int\
    \ idx;\n  };\n  vector<vector<edge>>g;\n  vector<int>min_cost,iter;\n  const T\
    \ INF;\n  Dinic(int v):INF(numeric_limits<T>::max()/2),g(v){}\n  void add_edge(int\
    \ from,int to,T cap,int idx=-1){\n    g[from].emplace_back(edge{to,cap,(int)g[to].size(),false,idx});\n\
    \    g[to].emplace_back(edge{from,0,(int)g[from].size()-1,true,idx});\n  }\n \
    \ bool build_path(int s,int t){\n    min_cost.assign(g.size(),-1);\n    queue<int>q;\n\
    \    min_cost[s]=0;\n    q.push(s);\n    while(!q.empty()&&min_cost[t]==-1){\n\
    \      int v=q.front();q.pop();\n      for(auto&e:g[v]){\n        if(e.cap>0&&min_cost[e.to]==-1){\n\
    \          min_cost[e.to]=min_cost[v]+1;\n          q.push(e.to);\n        }\n\
    \      }\n    }\n    return min_cost[t]!=-1;\n  }\n  T find_path(int idx,const\
    \ int t,T flow){\n    if(idx==t)return flow;\n    for(int &i=iter[idx];i<(int)g[idx].size();i++){\n\
    \      edge&e=g[idx][i];\n      if(e.cap>0&&min_cost[e.to]>min_cost[idx]){\n \
    \       T d=find_path(e.to,t,min(flow,e.cap));\n        if(d>0){\n          e.cap-=d;\n\
    \          g[e.to][e.rev].cap+=d;\n          return d;\n        }\n      }\n \
    \   }\n    return 0;\n  }\n  T max_flow(int s,int t){\n    T flow=0;\n    while(build_path(s,t)){\n\
    \      iter.assign(g.size(),0);\n      T f;\n      while((f=find_path(s,t,INF))>0)flow+=f;\n\
    \    }\n    return flow;\n  }\n};\n/**\n * @brief Dinic(\u6700\u5927\u6D41)\n\
    */\n"
  code: "#pragma once\ntemplate<typename T>\nstruct Dinic{\n  struct edge{\n    int\
    \ to;\n    T cap;\n    int rev;\n    bool isrev;\n    int idx;\n  };\n  vector<vector<edge>>g;\n\
    \  vector<int>min_cost,iter;\n  const T INF;\n  Dinic(int v):INF(numeric_limits<T>::max()/2),g(v){}\n\
    \  void add_edge(int from,int to,T cap,int idx=-1){\n    g[from].emplace_back(edge{to,cap,(int)g[to].size(),false,idx});\n\
    \    g[to].emplace_back(edge{from,0,(int)g[from].size()-1,true,idx});\n  }\n \
    \ bool build_path(int s,int t){\n    min_cost.assign(g.size(),-1);\n    queue<int>q;\n\
    \    min_cost[s]=0;\n    q.push(s);\n    while(!q.empty()&&min_cost[t]==-1){\n\
    \      int v=q.front();q.pop();\n      for(auto&e:g[v]){\n        if(e.cap>0&&min_cost[e.to]==-1){\n\
    \          min_cost[e.to]=min_cost[v]+1;\n          q.push(e.to);\n        }\n\
    \      }\n    }\n    return min_cost[t]!=-1;\n  }\n  T find_path(int idx,const\
    \ int t,T flow){\n    if(idx==t)return flow;\n    for(int &i=iter[idx];i<(int)g[idx].size();i++){\n\
    \      edge&e=g[idx][i];\n      if(e.cap>0&&min_cost[e.to]>min_cost[idx]){\n \
    \       T d=find_path(e.to,t,min(flow,e.cap));\n        if(d>0){\n          e.cap-=d;\n\
    \          g[e.to][e.rev].cap+=d;\n          return d;\n        }\n      }\n \
    \   }\n    return 0;\n  }\n  T max_flow(int s,int t){\n    T flow=0;\n    while(build_path(s,t)){\n\
    \      iter.assign(g.size(),0);\n      T f;\n      while((f=find_path(s,t,INF))>0)flow+=f;\n\
    \    }\n    return flow;\n  }\n};\n/**\n * @brief Dinic(\u6700\u5927\u6D41)\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/flow/dinic.hpp
  requiredBy: []
  timestamp: '2022-01-29 09:29:56+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_6_A.test.cpp
documentation_of: Graph/flow/dinic.hpp
layout: document
redirect_from:
- /library/Graph/flow/dinic.hpp
- /library/Graph/flow/dinic.hpp.html
title: "Dinic(\u6700\u5927\u6D41)"
---
