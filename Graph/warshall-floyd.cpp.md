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
  bundledCode: "#line 1 \"Graph/warshall-floyd.cpp\"\nvector<vector<long long>>warshall_floyd(vector<vector<long\
    \ long>>g){\n  int n=g.size();\n  for(int k=0;k<n;k++){\n    for(int i=0;i<n;i++){\n\
    \      for(int j=0;j<n;j++){\n        if(g[k][j]!=2e18){\n          g[i][j]=min(g[i][j],g[i][k]+g[k][j]);\n\
    \        }\n      }\n    }\n  }\n  return g;\n}\n"
  code: "vector<vector<long long>>warshall_floyd(vector<vector<long long>>g){\n  int\
    \ n=g.size();\n  for(int k=0;k<n;k++){\n    for(int i=0;i<n;i++){\n      for(int\
    \ j=0;j<n;j++){\n        if(g[k][j]!=2e18){\n          g[i][j]=min(g[i][j],g[i][k]+g[k][j]);\n\
    \        }\n      }\n    }\n  }\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/warshall-floyd.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/warshall-floyd.cpp
layout: document
redirect_from:
- /library/Graph/warshall-floyd.cpp
- /library/Graph/warshall-floyd.cpp.html
title: Graph/warshall-floyd.cpp
---
