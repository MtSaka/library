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
  bundledCode: "#line 1 \"Graph/topological-sort.cpp\"\nvector<int>t_sort(vector<vector<int>>g){\n\
    \  int n=g.size();\n  vector<int>deg(n,0);\n  for(int i=0;i<n;i++){\n    for(int\
    \ j:g[i]){\n      deg[j]++;\n    }\n  }\n  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n\
    \  vector<int>ans;\n  while(!q.empty()){\n    int v=q.front();\n    q.pop();\n\
    \    ans.push_back(v);\n    for(int w:g[v]){\n      deg[w]--;\n      if(deg[w]==0)q.push(w);\n\
    \    }\n  }\n  return ans;\n}\n"
  code: "vector<int>t_sort(vector<vector<int>>g){\n  int n=g.size();\n  vector<int>deg(n,0);\n\
    \  for(int i=0;i<n;i++){\n    for(int j:g[i]){\n      deg[j]++;\n    }\n  }\n\
    \  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n  vector<int>ans;\n\
    \  while(!q.empty()){\n    int v=q.front();\n    q.pop();\n    ans.push_back(v);\n\
    \    for(int w:g[v]){\n      deg[w]--;\n      if(deg[w]==0)q.push(w);\n    }\n\
    \  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Graph/topological-sort.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/topological-sort.cpp
layout: document
redirect_from:
- /library/Graph/topological-sort.cpp
- /library/Graph/topological-sort.cpp.html
title: Graph/topological-sort.cpp
---
