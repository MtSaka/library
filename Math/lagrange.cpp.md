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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../code/library/Math/com.cpp:\
    \ line -1: no such header\n"
  code: "#include<bits/stdc++.h>\n#include\"../../code/library/Math/com.cpp\"\nusing\
    \ namespace std;\ntemplate<long long m>\nmodint<m> lagrange_polynominal(vector<modint<m>>&y,long\
    \ long t){\n  using mint=modint<m>;\n  long long n=y.size()-1;\n  combination<m>c(n);\n\
    \  if(t<=n)return y[t];\n  mint ret;\n  vector<mint>dp(n+1,1),pd(n+1,1);\n  for(int\
    \ i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);\n  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);\n\
    \  for(int i=0;i<=n;i++){\n    mint tmp=y[i]*dp[i]*pd[i]*c.idat[i]*c.idat[n-i];\n\
    \    if((n-i)&1)ret-=tmp;\n    else ret+=tmp;\n  }\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/lagrange.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/lagrange.cpp
layout: document
redirect_from:
- /library/Math/lagrange.cpp
- /library/Math/lagrange.cpp.html
title: Math/lagrange.cpp
---
