---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../modular/ModInt.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"combinatorics.hpp\"\
    \n\ntemplate<long long m>\nModInt<m>lagrange_polynomial(const vector<ModInt<m>>&y,const\
    \ long long&t){\n  using mint=ModInt<m>;\n  const int n=y.size()-1;\n  Combinatorics<m>c(n);\n\
    \  if(t<=n)return y[t];\n  mint ret;\n  vector<mint>dp(n+1,1),pd(n+1,1);\n  for(int\
    \ i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);\n  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);\n\
    \  for(int i=0;i<=n;i++){\n    mint tmp=y[i]*dp[i]*pd[i]*c.finv(i)*c.finv(n-i);\n\
    \    if((n-i)&1)ret-=tmp;\n    else ret+=tmp;\n  }\n  return ret;\n}\n/**\n *\
    \ @brief Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/others/lagrange.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/others/lagrange.hpp
layout: document
redirect_from:
- /library/math/others/lagrange.hpp
- /library/math/others/lagrange.hpp.html
title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
---
