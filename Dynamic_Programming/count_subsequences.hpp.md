---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Count Subsequences(\u90E8\u5206\u5217\u306E\u500B\u6570)"
    links: []
  bundledCode: "#line 1 \"Dynamic_Programming/count_subsequences.hpp\"\nlong long\
    \ subcount(const string&s){\n  int n=s.size();\n  vector<vector<int>>next(n+1,vector<int>(26,0));\n\
    \  for(int i=n-1;i>=0;i--){\n    for(int j=0;j<26;j++)next[i][j]=next[i+1][j];\n\
    \    next[i][s[i]-'a']=i;\n  }\n  vector<long long>dp(n+1,0);\n  dp[0]=1;\n  for(int\
    \ i=0;i<n;i++)for(int j=0;j<26;j++)if(next[i][j]<n)dp[next[i][j]+1]=dp[next[i][j]+1]+dp[i];\n\
    \  long long ans=0;\n  for(int i=0;i<=n;i++)ans+=dp[i];\n  return ans;\n}\n/**\n\
    \ * @brief Count Subsequences(\u90E8\u5206\u5217\u306E\u500B\u6570)\n*/\n"
  code: "long long subcount(const string&s){\n  int n=s.size();\n  vector<vector<int>>next(n+1,vector<int>(26,0));\n\
    \  for(int i=n-1;i>=0;i--){\n    for(int j=0;j<26;j++)next[i][j]=next[i+1][j];\n\
    \    next[i][s[i]-'a']=i;\n  }\n  vector<long long>dp(n+1,0);\n  dp[0]=1;\n  for(int\
    \ i=0;i<n;i++)for(int j=0;j<26;j++)if(next[i][j]<n)dp[next[i][j]+1]=dp[next[i][j]+1]+dp[i];\n\
    \  long long ans=0;\n  for(int i=0;i<=n;i++)ans+=dp[i];\n  return ans;\n}\n/**\n\
    \ * @brief Count Subsequences(\u90E8\u5206\u5217\u306E\u500B\u6570)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Dynamic_Programming/count_subsequences.hpp
  requiredBy: []
  timestamp: '2022-01-12 16:26:09+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Dynamic_Programming/count_subsequences.hpp
layout: document
redirect_from:
- /library/Dynamic_Programming/count_subsequences.hpp
- /library/Dynamic_Programming/count_subsequences.hpp.html
title: "Count Subsequences(\u90E8\u5206\u5217\u306E\u500B\u6570)"
---