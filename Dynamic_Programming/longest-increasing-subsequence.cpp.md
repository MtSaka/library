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
  bundledCode: "#line 1 \"Dynamic_Programming/longest-increasing-subsequence.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\nconst long long inf=2e18;\ntemplate<typename\
    \ T>\nint lis(vector<T>&a){\n  int n=a.size();\n  vector<long long>dp(n,inf);\n\
    \  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];\n  return\
    \ lower_bound(dp.begin(),dp.end(),inf)-dp.begin();\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\nconst long long inf=2e18;\n\
    template<typename T>\nint lis(vector<T>&a){\n  int n=a.size();\n  vector<long\
    \ long>dp(n,inf);\n  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];\n\
    \  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/longest-increasing-subsequence.cpp
  requiredBy: []
  timestamp: '2021-08-31 20:08:40+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/longest-increasing-subsequence.cpp
layout: document
redirect_from:
- /library/Dynamic_Programming/longest-increasing-subsequence.cpp
- /library/Dynamic_Programming/longest-increasing-subsequence.cpp.html
title: Dynamic_Programming/longest-increasing-subsequence.cpp
---
