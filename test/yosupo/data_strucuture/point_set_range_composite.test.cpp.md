---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../others/monoid2.hpp\"\
    \n#include\"../../../math/modular/modint.hpp\"\n#include\"../../../ds/segment/segment-tree.hpp\"\
    \nusing mint=ModInt<998244353>;\nusing T=pair<mint,mint>;\nint main(){\n  INT(n,q);\n\
    \  vector<T>a(n);cin>>a;\n  SegmentTree<Monoid::Composite<mint>>seg(a);\n  while(q--){\n\
    \    INT(t,a,b,c);\n    if(t==0)seg.set(a,T{b,c});\n    else{\n      auto [x,y]=seg.prod(a,b);\n\
    \      print(x*c+y);\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_strucuture/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_strucuture/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_strucuture/point_set_range_composite.test.cpp
- /verify/test/yosupo/data_strucuture/point_set_range_composite.test.cpp.html
title: test/yosupo/data_strucuture/point_set_range_composite.test.cpp
---
