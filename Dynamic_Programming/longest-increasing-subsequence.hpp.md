---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_1_D.test.cpp
    title: test/aoj/DPL/DPL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Longest Increasing Subsequence(\u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217)"
    links: []
  bundledCode: "#line 1 \"Dynamic_Programming/longest-increasing-subsequence.hpp\"\
    \n/**\n * @brief Longest Increasing Subsequence(\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217)\n*/\ntemplate<typename T>\nint lis(const vector<T>&a){\n  int n=a.size();\n\
    \  vector<long long>dp(n,2e18);\n  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];\n\
    \  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();\n}\n"
  code: "/**\n * @brief Longest Increasing Subsequence(\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217)\n*/\ntemplate<typename T>\nint lis(const vector<T>&a){\n  int n=a.size();\n\
    \  vector<long long>dp(n,2e18);\n  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];\n\
    \  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/longest-increasing-subsequence.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL/DPL_1_D.test.cpp
documentation_of: Dynamic_Programming/longest-increasing-subsequence.hpp
layout: document
redirect_from:
- /library/Dynamic_Programming/longest-increasing-subsequence.hpp
- /library/Dynamic_Programming/longest-increasing-subsequence.hpp.html
title: "Longest Increasing Subsequence(\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217)"
---
