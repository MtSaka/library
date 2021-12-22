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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.cpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include\"../../template/template.cpp\"\
    \n#include\"../../Graph/lowest-common-ancestor.cpp\"\nint main(){\n  MtSaka;\n\
    \  INT(n,q);\n  vector<vector<int>>g(n);\n  rep(i,1,n){\n    INT(a);\n    g[i].push_back(a);\n\
    \    g[a].push_back(i);\n  }\n  LCA lca(g);\n  while(q--){\n    INT(u,v);\n  \
    \  print(lca.query(u,v));\n  }\n}"
  dependsOn:
  - template/template.cpp
  - Graph/lowest-common-ancestor.cpp
  isVerificationFile: true
  path: test/verify/yosupo-lca-3.test.cpp
  requiredBy: []
  timestamp: '2021-12-06 20:10:12+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-lca-3.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-lca-3.test.cpp
- /verify/test/verify/yosupo-lca-3.test.cpp.html
title: test/verify/yosupo-lca-3.test.cpp
---
