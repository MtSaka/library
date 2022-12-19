---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mo's Algorithm
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n\nstruct Mo{\n  int\
    \ n;\n  vector<int>left,right;\n  Mo(int n):n(n){}\n  void add(int l,int r){\n\
    \    left.push_back(l);\n    right.push_back(r);\n  }\n  template<typename AL,typename\
    \ AR,typename DL,typename DR,typename REM>\n  void run(const AL&add_left,const\
    \ AR&add_right,const DL&delete_left,const DR&delete_right,const REM&rem){\n  \
    \  const int q=left.size(),width=max<int>(1,int(sqrt(3)*n/sqrt(max(1,2*q))));\n\
    \    vector<int>order(q);\n    iota(order.begin(),order.end(),0);\n    sort(order.begin(),order.end(),[&](int\
    \ a,int b){\n      const int ablock=left[a]/width,bblock=left[b]/width;\n    \
    \  if(ablock!=bblock)return ablock<bblock;\n      return (ablock&1)?(right[a]>right[b]):(right[a]<right[b]);\n\
    \    });\n    int l=0,r=0;\n    for(auto idx:order){\n      while(l>left[idx])add_left(--l);\n\
    \      while(r<right[idx])add_right(r++);\n      while(l<left[idx])delete_left(l++);\n\
    \      while(r>right[idx])delete_right(--r); \n      rem(idx);\n    }\n  }\n \
    \ template<typename A,typename D,typename REM>\n  void run(const A&add,const D&del,const\
    \ REM&rem){\n    run(add,add,del,del,rem);\n  }\n};\n/**\n * @brief Mo's Algorithm\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: others/mo.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/mo.hpp
layout: document
redirect_from:
- /library/others/mo.hpp
- /library/others/mo.hpp.html
title: Mo's Algorithm
---
