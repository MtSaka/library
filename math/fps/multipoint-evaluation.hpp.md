---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../modular/ModInt.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"fps.hpp\"\
    \n\ntemplate<int m>\nvector<ModInt<m>>multipoint_evaluation(const FormalPowerSeries<m>&f,const\
    \ vector<ModInt<m>>&xs){\n  const int n=xs.size();\n  int sz=1;\n  while(sz<n)sz<<=1;\n\
    \  vector<FormalPowerSeries<m>>g(sz+sz,{1});\n  for(int i=0;i<n;i++)g[i+sz]={-xs[i],1};\n\
    \  for(int i=sz;i-->1;)g[i]=g[i<<1]*g[i<<1|1];\n  g[1]=f%g[1];\n  for(int i=2;i<sz+n;i++)g[i]=g[i>>1]%g[i];\n\
    \  vector<ModInt<m>>res(n);\n  for(int i=0;i<n;i++)res[i]=(g[i+sz].empty()?ModInt<m>():g[i+sz][0]);\n\
    \  return res;\n}\n/**\n * @brief Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1\
    )\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/fps/multipoint-evaluation.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/multipoint-evaluation.hpp
layout: document
redirect_from:
- /library/math/fps/multipoint-evaluation.hpp
- /library/math/fps/multipoint-evaluation.hpp.html
title: "Multipoint Evaluation(\u591A\u70B9\u8A55\u4FA1)"
---
