---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_10_C.test.cpp
    title: test/aoj/ALDS1/ALDS1_10_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\
      \u5217)"
    links: []
  bundledCode: "#line 1 \"Dynamic_Programming/longest_common-subsequence.hpp\"\ntemplate<typename\
    \ T>\nint lcsl(const vector<T>&a,const vector<T>&b){\n  vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n\
    \  for(int i=0;i<a.size();i++){\n    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  return dp[a.size()][b.size()];\n\
    }\ntemplate<typename T>\nvector<T>lcs(const vector<T>&a,const vector<T>&b){\n\
    \  vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  vector<T>ans;\n\
    \  int i=a.size(),j=b.size();\n  while(dp[i][j]){\n    if(dp[i-1][j]==dp[i][j])i--;\n\
    \    else if(dp[i][j-1]==dp[i][j])j--;\n    else i--,j--,ans.push_back(a[i]);\n\
    \  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}\n/**\n * @brief Longest\
    \ Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)\n*/\n"
  code: "template<typename T>\nint lcsl(const vector<T>&a,const vector<T>&b){\n  vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n\
    \  for(int i=0;i<a.size();i++){\n    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  return dp[a.size()][b.size()];\n\
    }\ntemplate<typename T>\nvector<T>lcs(const vector<T>&a,const vector<T>&b){\n\
    \  vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  vector<T>ans;\n\
    \  int i=a.size(),j=b.size();\n  while(dp[i][j]){\n    if(dp[i-1][j]==dp[i][j])i--;\n\
    \    else if(dp[i][j-1]==dp[i][j])j--;\n    else i--,j--,ans.push_back(a[i]);\n\
    \  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}\n/**\n * @brief Longest\
    \ Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/longest_common-subsequence.hpp
  requiredBy: []
  timestamp: '2022-01-12 16:26:09+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_10_C.test.cpp
documentation_of: Dynamic_Programming/longest_common-subsequence.hpp
layout: document
redirect_from:
- /library/Dynamic_Programming/longest_common-subsequence.hpp
- /library/Dynamic_Programming/longest_common-subsequence.hpp.html
title: "Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
---
