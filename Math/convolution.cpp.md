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
    \ namespace std;\nvector<long long>convolution(const vector<long long>&a,const\
    \ vector<long long>&b){\n  int n=a.size(),m=b.size();\n  if(!n||!m)return {};\n\
    \  static constexpr unsigned long long MOD1=754974721;\n  static constexpr unsigned\
    \ long long MOD2=167772161;\n  static constexpr unsigned long long MOD3=469762049;\n\
    \  static constexpr unsigned long long M2M3=78812994116517889;\n  static constexpr\
    \ unsigned long long M1M3=354658471880163329;\n  static constexpr unsigned long\
    \ long M1M2=126663740442542081;\n  static constexpr unsigned long long M1M2M3=560135205046714369;\n\
    \  static constexpr unsigned long long i1=190329765;\n  static constexpr unsigned\
    \ long long i2=58587104;\n  static constexpr unsigned long long i3=187290749;\n\
    \  NTT<MOD1>ntt1;\n  NTT<MOD2>ntt2;\n  NTT<MOD3>ntt3;\n  auto c1=ntt1.multiply(a,b);\n\
    \  auto c2=ntt2.multiply(a,b);\n  auto c3=ntt3.multiply(a,b);\n  vector<long long>c(n+m-1);\n\
    \  for(int i=0;i<n+m-1;i++){\n    unsigned long long x=0;\n    x+=(c1[i]*i1)%MOD1*M2M3;\n\
    \    x+=(c2[i]*i2)%MOD2*M1M3;\n    x+=(c3[i]*i3)%MOD3*M1M2;\n    long long diff=c1[i]-x%MOD1;\n\
    \    if(diff<0)diff+=MOD1;\n    static constexpr unsigned long long offset[5]={0,0,M1M2M3,2*M1M2M3,3*M1M2M3};\n\
    \    x-=offset[diff%5];\n    c[i]=x;\n  }\n  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/convolution.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/convolution.cpp
layout: document
redirect_from:
- /library/Math/convolution.cpp
- /library/Math/convolution.cpp.html
title: Math/convolution.cpp
---
