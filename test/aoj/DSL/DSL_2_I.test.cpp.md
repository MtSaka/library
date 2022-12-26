---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../data-structure/segment-tree-monoids.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I\"\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../data-structure/segment-tree-monoids.hpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  RUQRSQ<int>seg(n);\n  while(q--){\n   \
    \ int t;cin>>t;\n    if(t==0){\n      int l,r,x;cin>>l>>r>>x;\n      seg.apply(l,r+1,x);\n\
    \    }\n    else{\n      int l,r;cin>>l>>r;\n      cout<<seg.query(l,r+1)<<endl;\n\
    \    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_I.test.cpp
- /verify/test/aoj/DSL/DSL_2_I.test.cpp.html
title: test/aoj/DSL/DSL_2_I.test.cpp
---
