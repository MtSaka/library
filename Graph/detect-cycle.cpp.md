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
  bundledCode: "#line 1 \"Graph/detect-cycle.cpp\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nbool detect_cylce(vector<vector<int>>g){\n  int n=g.size();\n\
    \  vector<int>deg(n,0);\n  for(int i=0;i<n;i++){\n    for(int j:g[i]){\n     \
    \ deg[j]++;\n    }\n  }\n  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n\
    \  while(!q.empty()){\n    int v=q.front();\n    q.pop();\n    for(int w:g[v]){\n\
    \      deg[w]--;\n      if(deg[w]==0)q.push(0);\n    }\n  }\n  for(int i=0;i<n;i++)if(deg[i]!=0)return\
    \ true;\n  return false;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\nbool detect_cylce(vector<vector<int>>g){\n\
    \  int n=g.size();\n  vector<int>deg(n,0);\n  for(int i=0;i<n;i++){\n    for(int\
    \ j:g[i]){\n      deg[j]++;\n    }\n  }\n  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n\
    \  while(!q.empty()){\n    int v=q.front();\n    q.pop();\n    for(int w:g[v]){\n\
    \      deg[w]--;\n      if(deg[w]==0)q.push(0);\n    }\n  }\n  for(int i=0;i<n;i++)if(deg[i]!=0)return\
    \ true;\n  return false;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/detect-cycle.cpp
  requiredBy: []
  timestamp: '2021-08-23 15:16:18+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/detect-cycle.cpp
layout: document
redirect_from:
- /library/Graph/detect-cycle.cpp
- /library/Graph/detect-cycle.cpp.html
title: Graph/detect-cycle.cpp
---
