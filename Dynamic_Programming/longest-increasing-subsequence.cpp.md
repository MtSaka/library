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
    \ntemplate<typename T>\nint lis(vector<T>&a){\n  int n=a.size();\n  vector<long\
    \ long>dp(n,2e18);\n  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];\n\
    \  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();\n}\n"
  code: "template<typename T>\nint lis(vector<T>&a){\n  int n=a.size();\n  vector<long\
    \ long>dp(n,2e18);\n  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];\n\
    \  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/longest-increasing-subsequence.cpp
  requiredBy: []
  timestamp: '2021-11-17 20:52:48+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/longest-increasing-subsequence.cpp
layout: document
redirect_from:
- /library/Dynamic_Programming/longest-increasing-subsequence.cpp
- /library/Dynamic_Programming/longest-increasing-subsequence.cpp.html
title: Dynamic_Programming/longest-increasing-subsequence.cpp
---
