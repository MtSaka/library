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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../code/library/Math/ntt.cpp:\
    \ line -1: no such header\n"
  code: "#include<bits/stdc++.h>\n#include\"../../code/library/Math/ntt.cpp\"\nusing\
    \ namespace std;\nvector<long long>mod_convolution(vector<long long>a,vector<long\
    \ long>b,long long m){\n  NTT<167772161>ntt1;\n  NTT<469762049>ntt2;\n  NTT<1224736769>ntt3;\n\
    \  auto x=ntt1.multiply(a,b);\n  auto y=ntt2.multiply(a,b);\n  auto z=ntt3.multiply(a,b);\n\
    \  long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874,m12_mod=78812994116517889%m;\n\
    \  vector<long long>res(x.size());\n  for(int i=0;i<x.size();i++){\n    long long\
    \ v1=(y[i]-x[i])*m1_inv_m2%m2;\n    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/mod-ntt.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/mod-ntt.cpp
layout: document
redirect_from:
- /library/Math/mod-ntt.cpp
- /library/Math/mod-ntt.cpp.html
title: Math/mod-ntt.cpp
---
