---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Ford Fulkerson(\u6700\u5927\u6D41)"
    links: []
  bundledCode: "#line 2 \"Graph/flow/ford_fulkerson.hpp\"\ntemplate<typename T>\n\
    struct FordFulkerson{\n  struct edge{\n    int to;\n    T cap;\n    int rev;\n\
    \    bool isrev;\n    int idx;\n  };\n  const T INF;\n  vector<vector<edge>>g;\n\
    \  vector<int>used;\n  int timer;\n  FordFulkerson(int v):INF(numeric_limits<T>::max()/2),g(v),used(v,-1),timer(0){}\n\
    \  void add_edge(int from,int to,T cap,int idx=-1){\n    g[from].emplace_back(edge{to,cap,(int)g[to].size(),false,idx});\n\
    \    g[to].emplace_back(edge{from,0,(int)g[from].size()-1,true,idx});\n  }\n \
    \ T find_path(int idx,const int t,T flow){\n    if(idx==t)return flow;\n    used[idx]=timer;\n\
    \    for(auto&e:g[idx]){\n      if(e.cap>0&&used[e.to]!=timer){\n        T d=find_path(e.to,t,min(flow,e.cap));\n\
    \        if(d>0){\n          e.cap-=d;\n          g[e.to][e.rev].cap+=d;\n   \
    \       return d;\n        }\n      }\n    }\n    return 0;\n  }\n  T max_flow(int\
    \ s,int t){\n    T flow=0;\n    for(T f;(f=find_path(s,t,INF));timer++)flow+=f;\n\
    \    return flow;\n  }\n};\n/**\n * @brief Ford Fulkerson(\u6700\u5927\u6D41)\n\
    */\n"
  code: "#pragma once\ntemplate<typename T>\nstruct FordFulkerson{\n  struct edge{\n\
    \    int to;\n    T cap;\n    int rev;\n    bool isrev;\n    int idx;\n  };\n\
    \  const T INF;\n  vector<vector<edge>>g;\n  vector<int>used;\n  int timer;\n\
    \  FordFulkerson(int v):INF(numeric_limits<T>::max()/2),g(v),used(v,-1),timer(0){}\n\
    \  void add_edge(int from,int to,T cap,int idx=-1){\n    g[from].emplace_back(edge{to,cap,(int)g[to].size(),false,idx});\n\
    \    g[to].emplace_back(edge{from,0,(int)g[from].size()-1,true,idx});\n  }\n \
    \ T find_path(int idx,const int t,T flow){\n    if(idx==t)return flow;\n    used[idx]=timer;\n\
    \    for(auto&e:g[idx]){\n      if(e.cap>0&&used[e.to]!=timer){\n        T d=find_path(e.to,t,min(flow,e.cap));\n\
    \        if(d>0){\n          e.cap-=d;\n          g[e.to][e.rev].cap+=d;\n   \
    \       return d;\n        }\n      }\n    }\n    return 0;\n  }\n  T max_flow(int\
    \ s,int t){\n    T flow=0;\n    for(T f;(f=find_path(s,t,INF));timer++)flow+=f;\n\
    \    return flow;\n  }\n};\n/**\n * @brief Ford Fulkerson(\u6700\u5927\u6D41)\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/flow/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2022-01-29 09:50:16+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/flow/ford_fulkerson.hpp
layout: document
redirect_from:
- /library/Graph/flow/ford_fulkerson.hpp
- /library/Graph/flow/ford_fulkerson.hpp.html
title: "Ford Fulkerson(\u6700\u5927\u6D41)"
---
