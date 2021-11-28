---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-grl-1-c.test.cpp
    title: test/verify/aoj-grl-1-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/warshall-floyd.cpp\"\nvector<vector<long long>>warshall_floyd(vector<vector<long\
    \ long>>g){\n  int n=g.size();\n  for(int k=0;k<n;k++){\n    for(int i=0;i<n;i++){\n\
    \      for(int j=0;j<n;j++){\n        if(g[i][k]!=2e18&&g[k][j]!=2e18){\n    \
    \      g[i][j]=min(g[i][j],g[i][k]+g[k][j]);\n        }\n      }\n    }\n  }\n\
    \  return g;\n}\n"
  code: "vector<vector<long long>>warshall_floyd(vector<vector<long long>>g){\n  int\
    \ n=g.size();\n  for(int k=0;k<n;k++){\n    for(int i=0;i<n;i++){\n      for(int\
    \ j=0;j<n;j++){\n        if(g[i][k]!=2e18&&g[k][j]!=2e18){\n          g[i][j]=min(g[i][j],g[i][k]+g[k][j]);\n\
    \        }\n      }\n    }\n  }\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/warshall-floyd.cpp
  requiredBy: []
  timestamp: '2021-11-28 22:21:46+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/aoj-grl-1-c.test.cpp
documentation_of: Graph/warshall-floyd.cpp
layout: document
redirect_from:
- /library/Graph/warshall-floyd.cpp
- /library/Graph/warshall-floyd.cpp.html
title: Graph/warshall-floyd.cpp
---
