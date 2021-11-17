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
  bundledCode: "#line 1 \"Dynamic_Programming/longest-common-subsequence.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\ntemplate<typename T>\nint lcsl(vector<T>a,vector<T>b){\n\
    \  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n  for(int i=0;i<a.size();i++){\n\
    \    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  return dp[a.size()][b.size()];\n\
    }\ntemplate<typename T>\nvector<T>lcs(vector<T>a,vector<T>b){\n  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n\
    \  for(int i=0;i<a.size();i++){\n    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  vector<T>ans;\n\
    \  int i=a.size();,j=b.size();\n  while(dp[i][j]){\n    if(dp[i-1][j]==dp[i][j])i--;\n\
    \    else if(dp[i][j-1]==dp[i][j])j--;\n    else i--,j--,ans.push_back(a[i]);\n\
    \  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\ntemplate<typename T>\nint\
    \ lcsl(vector<T>a,vector<T>b){\n  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n\
    \  for(int i=0;i<a.size();i++){\n    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  return dp[a.size()][b.size()];\n\
    }\ntemplate<typename T>\nvector<T>lcs(vector<T>a,vector<T>b){\n  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));\n\
    \  for(int i=0;i<a.size();i++){\n    for(int j=0;j<b.size();j++){\n      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;\n\
    \      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);\n    }\n  }\n  vector<T>ans;\n\
    \  int i=a.size();,j=b.size();\n  while(dp[i][j]){\n    if(dp[i-1][j]==dp[i][j])i--;\n\
    \    else if(dp[i][j-1]==dp[i][j])j--;\n    else i--,j--,ans.push_back(a[i]);\n\
    \  }\n  reverse(ans.begin(),ans.end());\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/longest-common-subsequence.cpp
  requiredBy: []
  timestamp: '2021-08-31 20:08:40+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/longest-common-subsequence.cpp
layout: document
redirect_from:
- /library/Dynamic_Programming/longest-common-subsequence.cpp
- /library/Dynamic_Programming/longest-common-subsequence.cpp.html
title: Dynamic_Programming/longest-common-subsequence.cpp
---
