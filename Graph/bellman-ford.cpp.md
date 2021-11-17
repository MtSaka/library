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
  bundledCode: "#line 1 \"Graph/bellman-ford.cpp\"\nstruct Edge{\n  long long to;\n\
    \  long long cost;\n};\nusing Graph=vector<vector<Edge>>;\nvector<long long>bellman_ford(Graph\
    \ g,int s){\n  int n=g.size();\n  vector<long long>d(n,2e18);\n  d[s]=0;\n  while(true){\n\
    \    bool update=false;\n    for(int i=0;i<n;i++){\n      for(int j=0;j<g[i].size();j++){\n\
    \        long long c=g[i][j].to,v=g[i][j].cost;\n        if(d[v]>d[i]+c&&d[i]!=2e18){\n\
    \          d[v]=d[i]+c;\n          update=true;\n        }\n      }\n    }\n \
    \   if(!update)break;\n  }\n  return d;\n}\nbool negative_cycle(Graph g){\n  int\
    \ n=g.size();\n  vector<long long>d(n,0);\n  for(int i=0;i<n;i++){\n    bool update=false;\n\
    \    for(int j=0;j<n;j++){\n      for(int k=0;k<g[j].size();k++){\n        long\
    \ long c=g[j][k].to,v=g[j][k].cost;\n        if(d[v]>d[j]+c&&d[j]!=2e18){\n  \
    \        d[v]=d[j]+c;\n          update=true;\n          if(i==n-1)return true;\n\
    \        }\n      }\n    }\n    if(!update)break;\n  }\n  return false;\n}\n"
  code: "struct Edge{\n  long long to;\n  long long cost;\n};\nusing Graph=vector<vector<Edge>>;\n\
    vector<long long>bellman_ford(Graph g,int s){\n  int n=g.size();\n  vector<long\
    \ long>d(n,2e18);\n  d[s]=0;\n  while(true){\n    bool update=false;\n    for(int\
    \ i=0;i<n;i++){\n      for(int j=0;j<g[i].size();j++){\n        long long c=g[i][j].to,v=g[i][j].cost;\n\
    \        if(d[v]>d[i]+c&&d[i]!=2e18){\n          d[v]=d[i]+c;\n          update=true;\n\
    \        }\n      }\n    }\n    if(!update)break;\n  }\n  return d;\n}\nbool negative_cycle(Graph\
    \ g){\n  int n=g.size();\n  vector<long long>d(n,0);\n  for(int i=0;i<n;i++){\n\
    \    bool update=false;\n    for(int j=0;j<n;j++){\n      for(int k=0;k<g[j].size();k++){\n\
    \        long long c=g[j][k].to,v=g[j][k].cost;\n        if(d[v]>d[j]+c&&d[j]!=2e18){\n\
    \          d[v]=d[j]+c;\n          update=true;\n          if(i==n-1)return true;\n\
    \        }\n      }\n    }\n    if(!update)break;\n  }\n  return false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bellman-ford.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bellman-ford.cpp
layout: document
redirect_from:
- /library/Graph/bellman-ford.cpp
- /library/Graph/bellman-ford.cpp.html
title: Graph/bellman-ford.cpp
---
