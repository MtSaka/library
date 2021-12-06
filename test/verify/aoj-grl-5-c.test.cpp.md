---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/lowest-common-ancestor.cpp
    title: Graph/lowest-common-ancestor.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.cpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include\"../../template/template.cpp\"\n#include\"../../Graph/lowest-common-ancestor.cpp\"\
    \nint main(){\n  INT(n);\n  vector<vector<int>>g(n);\n  rep(i,n){\n    INT(k);\n\
    \    rep(j,k){\n      INT(a);\n      g[i].push_back(a);\n    }\n  }\n  INT(q);\n\
    \  if(n==1){\n    while(q--)print(0);\n    return 0;\n  }\n  LCA lca(g);\n  while(q--){\n\
    \    INT(a,b);\n    print(lca.query(a,b));\n  }\n}"
  dependsOn:
  - template/template.cpp
  - Graph/lowest-common-ancestor.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-5-c.test.cpp
  requiredBy: []
  timestamp: '2021-12-06 20:10:12+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-5-c.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-5-c.test.cpp
- /verify/test/verify/aoj-grl-5-c.test.cpp.html
title: test/verify/aoj-grl-5-c.test.cpp
---
