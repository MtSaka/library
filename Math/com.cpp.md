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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../code/library/Math/modint.cpp:\
    \ line -1: no such header\n"
  code: "#include<bits/stdc++.h>\n#include\"../../code/library/Math/modint.cpp\"\n\
    using namespace std;\ntemplate<long long m>\nstruct combination{\n  using mint=modint<m>;\n\
    \  vector<mint>dat,idat;\n  long long mx;\n  combination(long long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n\
    \    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n    idat[mx]/=dat[mx];\n\
    \    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n  }\n  mint com(long\
    \ long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n    return dat[n]*idat[k]*idat[n-k];\n\
    \  }\n  mint fac(long long n){\n    if(n<0)return mint(0);\n    return dat[n];\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/com.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/com.cpp
layout: document
redirect_from:
- /library/Math/com.cpp
- /library/Math/com.cpp.html
title: Math/com.cpp
---
