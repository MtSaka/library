---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dijkstra.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nconst long long inf=2e18;\nusing P=pair<long long,long long>;\nstruct\
    \ Edge {\n  long long to;\n  long long cost;\n};\nusing Graph=vector<vector<Edge>>;\n\
    vector<long long>dijkstra(Graph g,int s){\n  int n=g.size();\n  vector<long long>d(n,inf);\n\
    \  d[s]=0;\n  priority_queue<P,vector<P>,greater<P>>q;\n  q.push({0,s});\n  while(!q.empty()){\n\
    \    auto [c,v]=q.top();\n    q.pop();\n    if(d[v]>=c){\n      for(auto p:g[v]){\n\
    \        int w=p.to;\n        if(d[w]>d[v]+p.cost){\n          d[w]=d[v]+p.cost;\n\
    \          q.push({d[w],w});\n        }\n      }\n    }\n  }\n  return d;\n}\n\
    pair<long long,vector<long long>>dijkstra_path(Graph g,int s, int t){\n  int n=g.size();\n\
    \  vector<long long>d(n,inf);\n  d[s]=0;\n  vector<long long>prev(n);\n  priority_queue<P,vector<P>,greater<P>>q;\n\
    \  q.push({0,s});\n  while(!q.empty()){\n    auto [c,v]=q.top();\n    q.pop();\n\
    \    if(d[v]>=c){\n      for(auto p:g[v]){\n        int w=p.to;\n        if(d[w]>d[v]+p.cost){\n\
    \          d[w]=d[v]+p.cost;\n          q.push({d[w],w});\n          prev[w]=v;\n\
    \        }\n      }\n    }\n  }\n  if(d[t]==inf)return {-1,vector<long long>()};\n\
    \  else{\n    vector<long long>path;\n    path.push_back(t);\n    while(path.back()!=s){\n\
    \      path.push_back(prev[path.back()]);\n    }\n    reverse(path.begin(),path.end());\n\
    \    return {d[t],path};\n  }\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\nconst long long inf=2e18;\n\
    using P=pair<long long,long long>;\nstruct Edge {\n  long long to;\n  long long\
    \ cost;\n};\nusing Graph=vector<vector<Edge>>;\nvector<long long>dijkstra(Graph\
    \ g,int s){\n  int n=g.size();\n  vector<long long>d(n,inf);\n  d[s]=0;\n  priority_queue<P,vector<P>,greater<P>>q;\n\
    \  q.push({0,s});\n  while(!q.empty()){\n    auto [c,v]=q.top();\n    q.pop();\n\
    \    if(d[v]>=c){\n      for(auto p:g[v]){\n        int w=p.to;\n        if(d[w]>d[v]+p.cost){\n\
    \          d[w]=d[v]+p.cost;\n          q.push({d[w],w});\n        }\n      }\n\
    \    }\n  }\n  return d;\n}\npair<long long,vector<long long>>dijkstra_path(Graph\
    \ g,int s, int t){\n  int n=g.size();\n  vector<long long>d(n,inf);\n  d[s]=0;\n\
    \  vector<long long>prev(n);\n  priority_queue<P,vector<P>,greater<P>>q;\n  q.push({0,s});\n\
    \  while(!q.empty()){\n    auto [c,v]=q.top();\n    q.pop();\n    if(d[v]>=c){\n\
    \      for(auto p:g[v]){\n        int w=p.to;\n        if(d[w]>d[v]+p.cost){\n\
    \          d[w]=d[v]+p.cost;\n          q.push({d[w],w});\n          prev[w]=v;\n\
    \        }\n      }\n    }\n  }\n  if(d[t]==inf)return {-1,vector<long long>()};\n\
    \  else{\n    vector<long long>path;\n    path.push_back(t);\n    while(path.back()!=s){\n\
    \      path.push_back(prev[path.back()]);\n    }\n    reverse(path.begin(),path.end());\n\
    \    return {d[t],path};\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2021-08-23 15:16:18+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/dijkstra.cpp
- /library/Graph/dijkstra.cpp.html
title: Graph/dijkstra.cpp
---
