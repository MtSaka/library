---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\
      \u5217)"
    links: []
  bundledCode: "#line 1 \"Dynamic_Programming/longest-common-subsequence.hpp\"\n/**\n\
    \ * @brief Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
    )\n*/\ntemplate<typename T>\nint lcsl(const vector<T>&a,const vector<T>&b){\n\
    \  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  return dp[a.size()][b.size()];\n\
    }\ntemplate<typename T>\nvector<T>lcs(const vector<T>&a,const vector<T>&b){\n\
    \  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  vector<T>ans;\n\
    \  int i=a.size();,j=b.size();\n  while(dp[i][j]){\n    if(dp[i-1][j]==dp[i][j])i--;\n\
    \    else if(dp[i][j-1]==dp[i][j])j--;\n    else i--,j--,ans.push_back(a[i]);\n\
    \  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}\n"
  code: "/**\n * @brief Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\
    \u5217)\n*/\ntemplate<typename T>\nint lcsl(const vector<T>&a,const vector<T>&b){\n\
    \  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  return dp[a.size()][b.size()];\n\
    }\ntemplate<typename T>\nvector<T>lcs(const vector<T>&a,const vector<T>&b){\n\
    \  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  vector<T>ans;\n\
    \  int i=a.size();,j=b.size();\n  while(dp[i][j]){\n    if(dp[i-1][j]==dp[i][j])i--;\n\
    \    else if(dp[i][j-1]==dp[i][j])j--;\n    else i--,j--,ans.push_back(a[i]);\n\
    \  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/longest-common-subsequence.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/longest-common-subsequence.hpp
layout: document
redirect_from:
- /library/Dynamic_Programming/longest-common-subsequence.hpp
- /library/Dynamic_Programming/longest-common-subsequence.hpp.html
title: "Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
---
