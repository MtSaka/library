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
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../others/monoid2.hpp\"\
    \n#include\"../../../math/modular/modint.hpp\"\n#include\"../../../ds/segment/lazy-segment-tree.hpp\"\
    \nusing mint=ModInt<998244353>;\nusing T=pair<mint,mint>;\nint main(){\n  INT(n,q);\n\
    \  vector<mint>a(n);cin>>a;\n  LazySegmentTree<Monoid::AffineSum<mint>>seg(a);\n\
    \  while(q--){\n    INT(t);\n    if(t==0){\n      INT(l,r,b,c);\n      seg.apply(l,r,T{b,c});\n\
    \    }\n    else{\n      INT(l,r);\n      print(seg.prod(l,r));\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_strucuture/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_strucuture/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_strucuture/range_affine_range_sum.test.cpp
- /verify/test/yosupo/data_strucuture/range_affine_range_sum.test.cpp.html
title: test/yosupo/data_strucuture/range_affine_range_sum.test.cpp
---
