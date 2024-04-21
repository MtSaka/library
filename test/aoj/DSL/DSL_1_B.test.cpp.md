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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../ds/weighted-union-find.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../ds/weighted-union-find.hpp\"\
    \nint main(){\n  int n,m;\n  cin>>n>>m;\n  WeightedUnionFind<int>tree(n);\n  while(m--){\n\
    \    int a,b,c,d;\n    cin>>a>>b>>c;\n    if(a==0){\n      cin>>d;\n      tree.merge(b,c,d);\n\
    \    }\n    else{\n      if(tree.same(b,c)){\n        print(tree.dist(b,c));\n\
    \      }\n      else{\n        print('?');\n      }\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_1_B.test.cpp
- /verify/test/aoj/DSL/DSL_1_B.test.cpp.html
title: test/aoj/DSL/DSL_1_B.test.cpp
---
