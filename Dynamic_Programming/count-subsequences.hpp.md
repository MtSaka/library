---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Dynamic_Programming/count-subsequences.hpp\"\nlong long\
    \ subcount(string s){\n  int n=s.size();\n  vector<vector<int>>next(n+1,vector<int>(26,0));\n\
    \  for(int i=n-1;i>=0;i--){\n    for(int j=0;j<26;j++)next[i][j]=next[i+1][j];\n\
    \    next[i][s[i]-'a']=i;\n  }\n  vector<long long>dp(n+1,0);\n  dp[0]=1;\n  for(int\
    \ i=0;i<n;i++)for(int j=0;j<26;j++)if(next[i][j]<n)dp[next[i][j]+1]=dp[next[i][j]+1]+dp[i];\n\
    \  long long ans=0;\n  for(int i=0;i<=n;i++)ans+=dp[i];\n  return ans;\n}\n"
  code: "long long subcount(string s){\n  int n=s.size();\n  vector<vector<int>>next(n+1,vector<int>(26,0));\n\
    \  for(int i=n-1;i>=0;i--){\n    for(int j=0;j<26;j++)next[i][j]=next[i+1][j];\n\
    \    next[i][s[i]-'a']=i;\n  }\n  vector<long long>dp(n+1,0);\n  dp[0]=1;\n  for(int\
    \ i=0;i<n;i++)for(int j=0;j<26;j++)if(next[i][j]<n)dp[next[i][j]+1]=dp[next[i][j]+1]+dp[i];\n\
    \  long long ans=0;\n  for(int i=0;i<=n;i++)ans+=dp[i];\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/count-subsequences.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/count-subsequences.hpp
layout: document
redirect_from:
- /library/Dynamic_Programming/count-subsequences.hpp
- /library/Dynamic_Programming/count-subsequences.hpp.html
title: Dynamic_Programming/count-subsequences.hpp
---
