---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Convolution(\u7573\u307F\u8FBC\u307F)"
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
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../fast-prime/factorize.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"ntt.hpp\"\
    \n\ntemplate<typename T>\nvector<T>convolution(const vector<T>&a,const vector<T>&b){\n\
    \  const int n=a.size(),m=b.size();\n  if(!n||!m)return {};\n  static constexpr\
    \ unsigned long long MOD1=754974721ull,MOD2=167772161ull,MOD3=469762049ull,M2M3=78812994116517889ull,M1M3=354658471880163329ull,M1M2=126663740442542081ull,M1M2M3=560135205046714369ull,i1=190329765ull,i2=58587104,i3=187290749ull;\n\
    \  auto c1=NTT<MOD1>::multiply(a,b);\n  auto c2=NTT<MOD2>::multiply(a,b);\n  auto\
    \ c3=NTT<MOD3>::multiply(a,b);\n  vector<T>c(n+m-1);\n  static constexpr unsigned\
    \ long long offset[5]={0,0,M1M2M3,2*M1M2M3,3*M1M2M3};\n  for(int i=0;i<n+m-1;i++){\n\
    \    unsigned long long x=0;\n    x+=(c1[i]*i1)%MOD1*M2M3;\n    x+=(c2[i]*i2)%MOD2*M1M3;\n\
    \    x+=(c3[i]*i3)%MOD3*M1M2;\n    long long diff=c1[i]-x%MOD1;\n    if(diff<0)diff+=MOD1;\n\
    \    x-=offset[diff%5];\n    c[i]=x;\n  }\n  return c;\n}\n/**\n * @brief Convolution(\u7573\
    \u307F\u8FBC\u307F)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/convolution.hpp
- /library/math/convolution/convolution.hpp.html
title: "Convolution(\u7573\u307F\u8FBC\u307F)"
---
