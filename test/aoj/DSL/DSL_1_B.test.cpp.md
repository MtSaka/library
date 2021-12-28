---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/weighed_dsu.hpp
    title: "Weighed Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Data_Structure/weighed_dsu.hpp\"\
    \nint main(){\n  int n,m;\n  cin>>n>>m;\n  weighed_dsu<int>tree(n);\n  while(m--){\n\
    \    int a,b,c,d;\n    cin>>a>>b>>c;\n    if(a==0){\n      cin>>d;\n      tree.merge(b,c,d);\n\
    \    }\n    else{\n      if(tree.same(b,c)){\n        print(tree.dist(b,c));\n\
    \      }\n      else{\n        print('?');\n      }\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/weighed_dsu.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-12-24 23:34:27+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_1_B.test.cpp
- /verify/test/aoj/DSL/DSL_1_B.test.cpp.html
title: test/aoj/DSL/DSL_1_B.test.cpp
---
