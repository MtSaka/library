---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../ds/lazy-segment-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../ds/lazy-segment-tree.hpp\"\
    \nint main(){\n  INT(n,q);\n  RangeAddQueryRangeSumQuery<ll>RAQRSQ(n);\n  while(q--){\n\
    \    INT(t);\n    if(t==0){\n      INT(l,r,x);\n      RAQRSQ.apply(l-1,r,x);\n\
    \    }\n    else{\n      INT(l,r);\n      print(RAQRSQ.prod(l-1,r));\n    }\n\
    \  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_G.test.cpp
- /verify/test/aoj/DSL/DSL_2_G.test.cpp.html
title: test/aoj/DSL/DSL_2_G.test.cpp
---
