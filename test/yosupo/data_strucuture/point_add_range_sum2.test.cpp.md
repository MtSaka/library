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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../ds/segment/segment/binary-indexed-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"../../../template/template.hpp\"\n#include\"../../../ds/segment/segment/binary-indexed-tree.hpp\"\
    \nint main(){\n  INT(n,q);\n  BinaryIndexedTree<ll>bit(n);\n  for(int i=0;i<n;i++){\n\
    \    INT(a);\n    bit.add(i,a);\n  }\n  while(q--){\n    INT(t,l,r);\n    if(t)print(bit.sum(l,r));\n\
    \    else bit.add(l,r);\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_strucuture/point_add_range_sum2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_strucuture/point_add_range_sum2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_strucuture/point_add_range_sum2.test.cpp
- /verify/test/yosupo/data_strucuture/point_add_range_sum2.test.cpp.html
title: test/yosupo/data_strucuture/point_add_range_sum2.test.cpp
---
